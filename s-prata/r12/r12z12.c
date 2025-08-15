/*
    r12z12.c: Filtr uśredniający

    12. Obrazy cyfrowe, szczególnie te przesyłane drogą radiową z pojazdów 
    kosmicznych, mogą zawierać usterki. Uzupełnij program z ćwiczenia 11 o 
    funkcję poprawiającą jakość obrazu. Powinna ona porównywać każdą wartość z 
    jej "sąsiadami" z lewej, prawej, góry i dołu. Jeśli wartość różni się o 
    więcej niż 1 od każdego z sąsiadów, funkcja powinna zastąpić ją średnią 
    arytmetyczną wartości sąsiadujących. Średnia powinna zostać zaokrąglona 
    do najbliższej liczby całkowitej. Zauważ, że znaki na granicach rysunku 
    posiadają mniej niż czterech sąsiadów, wymagają więc specjalnego 
    traktowania.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOARD_WIDTH 30
#define BOARD_HEIGHT 20

void digits_to_signs(int picture_as_digits[][BOARD_WIDTH], char picture_as_signs[][BOARD_WIDTH + 1], int lines);
void show_picture(char [][BOARD_WIDTH + 1], int lines);
void save_picture(char picture_as_signs[][BOARD_WIDTH + 1], int lines, char *filename);
void mean_filter(int [][BOARD_WIDTH], int lines);

int main(void) {

    int picture_as_digits[BOARD_HEIGHT][BOARD_WIDTH];
    char picture_as_signs[BOARD_HEIGHT][BOARD_WIDTH + 1];

    FILE *file = fopen("static/danewe.txt", "r");

    if(file == NULL) {
        fprintf(stderr, "Nie moge otworzyc pliku danewe.txt \n");
        return 1;
    }

    int digit = 0;
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            if(fscanf(file, "%d", &digit) == 1) {
                picture_as_digits[i][j] = digit;
            }
        }
    }

    fclose(file);

    digits_to_signs(picture_as_digits, picture_as_signs, BOARD_HEIGHT);
    show_picture(picture_as_signs, BOARD_HEIGHT);
    save_picture(picture_as_signs, BOARD_HEIGHT, "static/danewy.txt");

    mean_filter(picture_as_digits, BOARD_HEIGHT);

    digits_to_signs(picture_as_digits, picture_as_signs, BOARD_HEIGHT);
    show_picture(picture_as_signs, BOARD_HEIGHT);
    save_picture(picture_as_signs, BOARD_HEIGHT, "static/danewy-filter.txt");

    return 0;
}

void digits_to_signs(int picture_as_digits[][BOARD_WIDTH], char picture_as_signs[][BOARD_WIDTH + 1], int lines) {

    const char picture_symbols[] = { ' ', '.', '\'', ':', '~', '*', '=', '$', '%', '#' };

    for(int i = 0; i < lines; i++) {
        int j = 0;
        while(j < BOARD_WIDTH) {
            int picture_point = picture_as_digits[i][j];
            picture_as_signs[i][j] = picture_symbols[picture_point];
            j++;
        }

        picture_as_signs[i][j] = '\0';
    }
}

void show_picture(char picture_as_signs[][BOARD_WIDTH + 1], int lines) {

    for(int i = 0; i < lines; i++) {
        printf("%s \n", picture_as_signs[i]);
    }
}

void save_picture(char picture_as_signs[][BOARD_WIDTH + 1], int lines, char *filename) {

    FILE *file = fopen(filename, "w");

    if(file == NULL) {
        fprintf(stderr, "Nie moge otworzyc pliku do zapisu danewy.txt \n");
        exit(2);
    }

    for(int i = 0; i < lines; i++) {
        fputs(picture_as_signs[i], file);
        fputs("\n", file);
    }

    fclose(file);
}

void mean_filter(int picture_as_digits[][BOARD_WIDTH], int lines) {

    const int MASK_SIZE = 6;

    enum {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        POINT,
        COUNT_NEIGHBORS
    };

    int mean_mask[MASK_SIZE] = { 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {

            // clear mean_mask
            for (int k = 0; k < MASK_SIZE; k++) {
                mean_mask[k] = 0;
            }

            mean_mask[POINT] = picture_as_digits[i][j];

            if (j > 0) {
                mean_mask[LEFT] = picture_as_digits[i][j-1];
                mean_mask[COUNT_NEIGHBORS]++;
            }

            if (j < BOARD_WIDTH - 1) {
                mean_mask[RIGHT] = picture_as_digits[i][j+1];
                mean_mask[COUNT_NEIGHBORS]++;
            }

            if (i < lines - 1) {
                mean_mask[DOWN] = picture_as_digits[i+1][j];
                mean_mask[COUNT_NEIGHBORS]++;
            }

            if (i > 0) {
                mean_mask[UP] = picture_as_digits[i-1][j];
                mean_mask[COUNT_NEIGHBORS]++;
            }

            int diff_left = abs(mean_mask[POINT] - mean_mask[LEFT]);
            int diff_right = abs(mean_mask[POINT] - mean_mask[RIGHT]);
            int diff_up = abs(mean_mask[POINT] - mean_mask[UP]);
            int diff_down = abs(mean_mask[POINT] - mean_mask[DOWN]);

            if (diff_left > 1 && diff_right > 1 && diff_up > 1 && diff_down > 1) {

                double avg = (mean_mask[LEFT] + mean_mask[RIGHT] + mean_mask[UP] + mean_mask[DOWN]) / (double)mean_mask[COUNT_NEIGHBORS];
                mean_mask[POINT] = (int)round(avg);
                picture_as_digits[i][j] = mean_mask[POINT];
            }
        }
    }
}

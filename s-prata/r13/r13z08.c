/*
    r13z08.c: Sortowanie i zapisywanie słów do pliku

    8. Napisz program interaktywny, który pozwala wpisać do 20 słów, wyświetla 
    je w kolejności alfabetycznej (zajrzyj do programu sortującego łańcuchy z 
    Rozdziału 11 "Łańcuchy znakowe i funkcje łańcuchowe"), a następnie pyta 
    użytkownika, czy powinny one zostać zapisane w pliku. Jeśli użytkownik 
    odpowie twierdząco, program powinien poprosić o podanie nazwy pliku, a 
    następnie dokonać zapisu.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DATA_SIZE  20
#define LINE_SIZE  1024
#define FILE_LABEL 21

int insert(char words[][LINE_SIZE], int);
void show_lines(char *[], int);
void sort_ascii(char *[], int);
bool save_to_file(char **words, int size, char *filename);

int main(void) {

    char words[DATA_SIZE][LINE_SIZE];

    printf("Wprowadz tekst (max %d linii): \n", DATA_SIZE);
    int data_size = insert(words, DATA_SIZE);

    // copy data
    char *copy_words[DATA_SIZE];
    for(int i = 0; i < data_size; i++) {
        copy_words[i] = &words[i][0];
    }

    sort_ascii(copy_words, data_size);
    show_lines(copy_words, data_size);
    
    printf("Zapisac dane do pliku? (t/n): ");

    char option = 'n';
    scanf("%c", &option);
    
    if(option != 't' && option != 'T') {

        printf("Dane nie zostaly zapisane. \n");
        return false;
    }
    
    printf("Podaj nazwe pliku oraz rozszerzenie: ");
    
    char filename[FILE_LABEL];
    scanf("%s", filename);

    save_to_file(copy_words, data_size, filename);
    printf("Dane zostaly zapisane w pliku %s. \n", filename);

    return true;
}

int insert(char words[][LINE_SIZE], int limit) {

    int size = 0;
    while(size < limit && fgets(words[size], LINE_SIZE, stdin) != NULL) {

        if(words[size][1] == '\0') {
            break;
        } else {
            words[size][strlen(words[size])-1] = '\0';
        }

        size += 1;
    }

    return size;
}

void show_lines(char *lines[], int size) {

    for(int i = 0; i < size; i++) {
        printf("%d) %s \n", i+1, lines[i]);
    }

    printf("\n");
}

void sort_ascii(char *lines[], int size) {

    for(int i = 0; i < size; i++) {

        for(int j = 0; j < size - 1; j++) {

            if(strcmp(lines[j], lines[j+1]) > 0) {
                char *swap = lines[j];
                lines[j] = lines[j+1];
                lines[j+1] = swap;
            }
        }
    }
}

bool save_to_file(char **words, int size, char *filename) {
    FILE *file = fopen(filename, "w");

    if(file == NULL) {
        fprintf(stderr, "Nie moge otworzyc pliku %s. \n", filename);
        return false;
    }

    int i = 0;
    while(i < size && fputs(words[i], file) != EOF) {
        fputs("\n", file);
        i += 1;
    }

    fclose(file);

    return true;
}

/*
    r12z10.c: Cyfrowa reprezentacja rysunku

    Utwórz plik tekstowy składający się z 20 rzędów po 30 liczb całkowitych 
    rozdzielonych odstępami. Liczby powinny należeć do przedziału 0–9. Niech 
    plik ten będzie cyfrową reprezentacją rysunku, a wartości od 0 do 9 
    oznaczają coraz większe poziomy zaczernienia. Napisz program, który wczytuje
    zawartość pliku do tablicy 20 × 30 wartości typu int. Aby zamienić ten 
    zbiór liczb na rysunek, program powinien użyć wartości z tej tablicy do 
    zainicjalizowania kolejnej tablicy, tym razem złożonej z 20 na 31 wartości 
    typu char. Liczbie 0 powinien odpowiadać odstęp, liczbie 1 – kropka,
    i tak dalej, tak, aby większym liczbom odpowiadały picture_as_signs, które zajmują 
    więcej miejsca. Liczbę 9 może na przykład symbolizować znak #. Ostatni (31.) 
    znak w każdym rzędzie powinien być picture_as_signsem zerowym tak, aby utworzyć 
    tablicę 20 łańcuchów. Program powinien wyświetlić rysunek (czyli kolejne 
    łańcuchy) na ekranie oraz zapisać go w pliku tekstowym. Na 
    przykład, załóżmy, że plik wejściowy zawiera następujące dane 
    (znajdziesz je w pliku danewe.txt dostępnym razem z programami 
    przykładowymi w Internecie):

    0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
    0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
    0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
    5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
    8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
    9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
    8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
    5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
    0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
    0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
    0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
    0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
    0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0

    Dane wyjściowe mogły wyglądać następująco (są one zapisane w pliku danewy.txt):

      #         *%##%*'           
        #       *%##%**'          
                *%.#%*~*'         
        #       *%##%* ~*'        
      #         *%##%*  ~*'       
                *%#.%*   ~*'      
                *%##%*    ~*'     
    *************%##%*************
    %%%%%%%%%%%%*%##%*%%%%%%%%%%%%
    #### #################:#######
    %%%%%%%%%%%%*%##%*%%%%%%%%%%%%
    *************%##%*************
                *%##%*            
                *%##%*    ==      
        ''      *%##%*  *=  =*    
        ::      *%##%* *=....=*   
        ~~      *%##%*  *=  =*    
        **      *%##%*    ==      
                *%##%*            
                *%##%*  
*/

#include <stdio.h>
#include <stdlib.h>

#define BOARD_WIDTH 30
#define BOARD_HEIGHT 20

void show_picture(char [][BOARD_WIDTH + 1], int lines);
void convert_to_picture(char [][BOARD_WIDTH + 1], int lines);

int main(void) {

    int picture_as_digits[BOARD_HEIGHT][BOARD_WIDTH];
    char picture_as_signs[BOARD_HEIGHT][BOARD_WIDTH + 1];
    const char picture_symbols[] = { ' ', '.', '\'', ':', '~', '*', '=', '$', '%', '#' };

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

    char picture_point = 'x';
    for(int i = 0; i < BOARD_HEIGHT; i++) {

        int j = 0;
        while(j < BOARD_WIDTH) {

            picture_point = picture_as_digits[i][j];
            picture_as_signs[i][j] = picture_symbols[picture_point];
            j++;
        }
        
        picture_as_signs[i][j] = '\0';
    }

    show_picture(picture_as_signs, BOARD_HEIGHT);
    convert_to_picture(picture_as_signs, BOARD_HEIGHT);

    return 0;
}

void show_picture(char picture_as_signs[][BOARD_WIDTH+1], int lines) {

    for(int i = 0; i < lines; i++) {
        printf("%s \n", picture_as_signs[i]);
    }
}

void convert_to_picture(char picture_as_signs[][BOARD_WIDTH + 1], int lines) {

    FILE *file = fopen("static/danewy.txt", "w");

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

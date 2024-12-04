/*
    r06z01.c: Tabica zawierająca 26 małych liter

    1. Napisz program, który tworzy tablicę 26 elementów, zapisuje w niej 26 
    małych liter, a następnie wyświetla jej zawartość.
*/

#include <stdio.h>

const int CHAR_ARRAY_SIZE = 26;

int main(void) {

    char signs[CHAR_ARRAY_SIZE];

    char sign = 'a';
    for(int i = 0; i < CHAR_ARRAY_SIZE; i++) {
        signs[i] = sign;
        sign += 1;
    }

    printf("Tablica znakow: \n");
    for(int i = 0; i < CHAR_ARRAY_SIZE; i++) {
        printf("%-3c", signs[i]);
    }

    printf("\n");

    return 0;
}

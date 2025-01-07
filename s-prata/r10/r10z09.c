/*
    r10z09.c: Podwajanie elementów tablicy dwuwymiarowej

    9. Napisz program, który deklaruje tablicę o wymiarach 3 na 5 i przypisuje 
    jej jakieś wartości początkowe, a następnie wyświetla wartości, podwaja 
    je i wyświetla nowe wartości. Wyświetlaniem i podwajaniem powinny zajmować 
    się osobne funkcje, pobierające jako argumenty nazwę tablicy oraz 
    liczbę rzędów.
*/

#include <stdio.h>

const int ROWS = 3;
const int COLS = 5;

void show(int [][COLS], int);
void mul2(int [][COLS], int);

int main(void) {

    int digits[ROWS][COLS] = {
        { 1,2,3,4,5 },
        { 6,7,8,9,9 },
        { 4,5,8,1,0 }
    };

    printf("Przed: \n");
    show(digits, ROWS);

    printf("\n");
    mul2(digits, ROWS);

    printf("Po: \n");
    show(digits, ROWS);


    return 0;
}

void show(int digits[][COLS], int rows) {

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < COLS; j++) {
            printf("%4d", digits[i][j]);  
        }

        printf("\n");
    }
}

void mul2(int digits[][COLS], int rows) {

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < COLS; j++) {
            digits[i][j] *= 2;
        }
    }
}

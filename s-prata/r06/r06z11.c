/*
    r06z11.c: Pierwsze osiem potęg liczby 2

    11. Napisz program, który tworzy 8-elementową tablicę typu 'int', 
    przypisuje jej elementom pierwsze osiem potęg liczby 2, po czym wyświetla 
    te wartości. Do przypisania wartości użyj pętli 'for', a do wyświetlenia 
    wartości – dla urozmaicenia – pętli 'do while'.
*/

#include <stdio.h>

const int ARRAY_SIZE = 8;

int main(void) {

    int digits[ARRAY_SIZE] = { 1, 1, 1, 1, 1, 1, 1, 1 };
    int pow = 2;

    // insert data
    for(int i = 0; i < ARRAY_SIZE; i++) {

        digits[i] = pow;

        pow *= 2;
    }

    // show data
    int i = 0; 
    do {

        printf("%d). %d \n", i+1, digits[i]);

    } while(++i < ARRAY_SIZE);

    return 0;
}

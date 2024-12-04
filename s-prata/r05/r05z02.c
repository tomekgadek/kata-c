/*
    r05z02.c: Wyświetl liczby całkowite

    2. Napisz program, który prosi o podanie liczby całkowitej, a następnie 
    wyświetla wszystkie liczby całkowite od tej wartości do wartości większej o 10 (włącznie). 
    (Jeśli zatem wpisano liczbę 5, program wyświetla liczby od 5 do 15.)
*/

#include <stdio.h>

const int SHIFT = 10;

int main(void) {

    int digit_start = 0, digit_stop = 0;

    printf("Podaj liczbe poczatkowa: ");
    scanf("%d", &digit_start);

    digit_stop = digit_start + SHIFT;

    while(digit_start <= digit_stop) {
        printf("%d ", digit_start);
        digit_start += 1;
    }

    putchar('\n');
}

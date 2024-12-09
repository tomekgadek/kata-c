/*
    r06z09.c: Wyświetl liczby całkowite w odwrotnej kolejności

    9. Napisz program, który wczytuje osiem liczb całkowitych do tablicy, a 
    następnie wyświetla je w odwrotnej kolejności.
*/

#include <stdio.h>

#define DIGITS_SIZE 8

int main(void) {

    int digits[DIGITS_SIZE];

    printf("Podaj liczby calkowite: \n");

    for(int i = 0; i < DIGITS_SIZE; i++) {

        printf("digit(%d) = ", i);
        scanf("%d", &digits[i]);
    }

    printf("Liczby w odwrotnej kolejnosci: \n");

    for(int i = DIGITS_SIZE - 1; i >= 0; --i) {
        printf("%d \n", digits[i]);
    }

    return 0;
}

/*
    r13z01.c: wyswietl.c -- wyswietla tablice 
*/

#include <stdio.h>

void wyswietl(const int tablica[], int granica) {

    int index;

    for (index = 0; index < granica; index++) {
        printf("%d ", tablica[index]);
        if (index % 10 == 9) {
            putchar('\n');
        }
    }

    if (index % 10 != 0) {
        putchar('\n');
    }
}

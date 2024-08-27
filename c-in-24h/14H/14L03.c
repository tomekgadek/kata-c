/* 14L03.c: Zastosowanie specyfikatora static zmiennej statycznej */

#include <stdio.h>

int sumuj_dwie(int x, int y) {
    static int licznik = 1; /* liczy wywolania funkcji */

    printf("Wywolanie funkcji, stan licznika: %d\n", licznik++);
    return (x+y);
}

int main(void) {

    int i, j;

    for(i = 0, j = 5; i < 5; i++, j--)
        printf("Dodawanie liczb: %d oraz %d suma: %d\n", i, j, sumuj_dwie(i,j));

    return 0;
}

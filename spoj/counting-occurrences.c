/*
    counting-occurrences.c: KC004 - Zliczanie wystąpień

    Zadanie: https://pl.spoj.com/problems/KC004/

    Kompilacja oraz uruchomienie programu: gcc counting-occurrences.c && ./a.out < ./tests/counting-occurrences-tests.txt
*/
#include <stdio.h>

int main(void) {

    int search = 0;
    while(scanf("%d", &search) == 1) {

        int how_many_digits = 0;
        scanf("%d", &how_many_digits);

        int counter = 0;
        for(int digit = 0; how_many_digits > 0; --how_many_digits) {

            scanf("%d", &digit);
            if(search == digit) {
                counter++;
            }
        }

        printf("%d \n", counter);
    }

    return 0;
}

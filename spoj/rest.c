/*
    rest.c: AL_06_01 - Reszta z dzielenia

    Zadanie: https://pl.spoj.com/problems/AL_06_01/

    Kompilacja oraz uruchomienie programu: gcc rest.c && ./a.out < ./tests/rest-tests.txt
*/
#include <stdio.h>

int main(void) {

    long int how_many_tests = 0;

    scanf("%ld", &how_many_tests);

    for(long int a = 0, b = 0; how_many_tests > 0; how_many_tests--) {

        scanf("%ld %ld", &a, &b);

        if(b != 0) {
            printf("%ld \n", a % b);
        }
    }

    return 0;
}

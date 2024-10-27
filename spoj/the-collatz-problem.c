/*
    the-collatz-problem.c: PTCLTZ - Problem Collatza

    Zadanie: https://pl.spoj.com/problems/PTCLTZ/

    Kompilacja oraz uruchomienie programu: gcc the-collatz-problem.c && ./a.out < ./tests/the-collatz-problem-tests.txt
*/
#include <stdio.h>

int main(void) {

    int how_many_tests = 0;

    scanf("%d", &how_many_tests);

    for(int Xn = 0, s = 0, n = 0; how_many_tests > 0; how_many_tests--) {

        scanf("%d", &s);

        if(s > 1) {

            for(n = 0, Xn = 0; Xn != 1; n++) {
                Xn = (s % 2 == 0 ? s / 2 : 3 * s + 1);
                s = Xn;
            }
        }

        printf("%d \n", n);
    }

    return 0;
}

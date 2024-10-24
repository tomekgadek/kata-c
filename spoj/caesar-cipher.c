/*
    caesar-sipher.c: JSZYCER - Szyfr Cezara

    Zadanie: https://pl.spoj.com/problems/JSZYCER/

    Kompilacja oraz uruchomienie programu: gcc caesar-cipher.c && ./a.out < ./tests/caesar-cipher-tests.txt
*/
#include <stdio.h>

#define SIGN_SHIFT 3
#define A 'A'
#define Z 'Z'

int main(void) {

    char sign = '_';

    while((sign = getc(stdin)) != EOF) {
        if(sign >= A && sign <= Z) {
            for(int i = 0; i < SIGN_SHIFT; i++ ) {
                if(sign == Z) {
                    sign = A;
                    sign -= 1;
                }

                sign++;
            }
        }

        putc(sign, stdout);
    }

    putchar('\n');

    return 0;
}

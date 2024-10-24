/*
    html-tags.c: JHTMLLET - Tagi HTML

    Zadanie: https://pl.spoj.com/problems/JHTMLLET/

    Kompilacja oraz uruchomienie programu: gcc html-tags.c && ./a.out < ./tests/html-tags-test.txt
*/
#include <stdio.h>

#define TAG_OPEN  '<'
#define TAG_CLOSE '>'
#define SIGN_SHIFT 32
#define A 'a'
#define Z 'z'

int main(void) {
    char sign = '_';

    while((sign = getc(stdin)) != EOF) {
        putchar(sign);

        if(sign == TAG_OPEN) {
            while((sign = getc(stdin)) != TAG_CLOSE) {
                putchar(sign >= A && sign <= Z ? sign - SIGN_SHIFT : sign);
            }

            putchar(sign);
        }
    }

    putchar('\n');
    return 0;
}

/* 07L03.c: Zamiana 0...15 na liczby szesnastkowe */

#include <stdio.h>

int main(void) {

    int i;
    printf("16(D.Litery) 16(m.Litery)  10:\n");

    for(i = 0; i < 16; i++) {
        printf("%X            %x             %d\n", i, i, i);
    }

    return 0;
}

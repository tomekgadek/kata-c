/* 14L01.c: Zmienne lokalne w blokach zagniezdzonych */

#include <stdio.h>

int main(void) {

    int i = 32; /* blok zewnetrzny (1) */

    printf("W bloku zewnetrznym: i = %d\n", i);

    { /* poczatek bloku wewnetrznego (2) */

        int i, j; /* zasieg w bloku wewnetrznym(2) */

        printf("W bloku wewnetrznym:\n");
        for(i = 0, j = 10; i <= 10; i++, j--) {
            printf("i = %2d, j = %2d\n" ,i ,j);
        }
    } /* koniec bloku wewnetrznego (2) */

    printf("Znowu w bloku zewnetrznym: i = %d\n", i);

    return 0;
}

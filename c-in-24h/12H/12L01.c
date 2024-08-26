/* 12L01.c: Inicjowanie tablicy int list_int = [10] = {1, 2, 3, 4, ...10} */

#include <stdio.h>

int main(void) {

    int i;
    int tab[10];
    
    for(i = 0; i < 10; i++) {

        tab[i] = i + 1;
        printf("Element tablicy tab[%d] ma wartosc %d.\n", i, tab[i]);
    }

    return 0;
}

/* 08L03.c: Operatory logiczne(Suma logiczna) */

#include <stdio.h>

int main(void) {

    int num;
    
    printf("Wpisz jednocyfrowa liczbe podzielna\ni przez 2 i przez 3.\n");

    for(num = 1; (num % 2 != 0) || (num % 3 != 0); ) {
        num = getchar() - 48;
    }

    printf("Tak! To ta liczba %d\n", num);

    return 0;
}

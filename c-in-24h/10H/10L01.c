/* 10L01.c: Zastosowanie instrukcji if */

#include <stdio.h>

int main(void) {

    int i;
    
    printf("Liczby calkowite podzielne przez 2 i przez 3\n");
    printf("W zaskresie od 0 do 100\n");
    for(i = 0; i <= 100; i++) {
        if((i % 2 == 0) && (i % 3 == 0)) {
            printf("   %d\n", i);
        }
    }

    return 0;
}

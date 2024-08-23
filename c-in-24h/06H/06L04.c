/* 06L04.c: Zastosowanie operatora rzutowania typu */

#include <stdio.h>

int main(void) {

    int x = 7, y = 5; /* deklaracja i zainicjowanie zmiennych */
    
    printf("Dane: x = %d, y = %d\n", x, y);
    printf("Operacja x / y daje wynik: %d\n", x / y);
    printf("Operacja (float)x / y daje wynik: %f\n", (float)x / y);

    return 0;
}

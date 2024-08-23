/* 06L03.c: Zastosowanie operatorow relacji - wyniki porownan */

#include <stdio.h>

int main(void) {

    int x, y;
    double z;
 
    x = 7;
    y = 25;
    z = 24.46;
    
    printf("Dane sa zmienne: x = %d, y = %d oraz z = %.2f,\n", x, y, z);
    printf("Operacja x >= y daje wynik: %d\n", x >= y);
    printf("Operacja x == y daje wynik: %d\n", x == y);
    printf("Operacja x < z daje wynik: %d\n", x < z);
    printf("Operacja y > z daje wynik: %d\n",y > z);
    printf("Porownanie x != y - 18 daje wynik: %d\n",x != y - 18);
    printf("Operacja x + y != z daje wynik: %d\n", x + y != z);

    return 0;
}

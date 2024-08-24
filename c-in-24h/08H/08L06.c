/* 08L06.c: Zastosoanie operatorow przesuniecia */

#include <stdio.h>

int main(void) {

    int x, y, z;

    x = 255;
    y = 5;
    
    printf("Dane x = %4d, czyli, 0x%04X\n", x, x);
    printf("     y = %4d, czyli, 0x%04X\n", y, y);
    z = x >> y;
    printf("x >> y zwraca: %6d, czyli, 0x%04X\n", z, z);
    z = x << y;
    printf("x << y zwraca: %6d, czyli, 0x%04X\n", z, z);

    return 0;
}

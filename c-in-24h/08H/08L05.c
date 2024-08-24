/* 08L05.c: Zastosowanie operatorow bitowych */

#include <stdio.h>

int main(void)
{
    int x, y, z;

    x = 4321;
    y = 5678;

    printf("Dana jest zmienna x = %u, czyli, 0x%04X\n", x, x);
    printf("oraz zmienna y = %u, czyli, 0x%04X\n", y, y);
    z = x & y;
    printf("x & y zwraca: %6u, czyli, 0x%04X\n", z, z);
    z = x | y;
    printf("x | y zwraca: %6u, czyli, 0x%04X\n", z, z);
    z = x ^ y;
    printf("x ^ y zwraca: %6u, czyli, 0x%04X\n", z, z);
    printf("~x zwraca: %6u, czyli, 0x%04X\n", ~x, ~x);

    return 0;
}

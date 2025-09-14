/*
    r15z05.c: Program obracający bity w lewo

    5. Napisz funkcję, która "obraca" bity w wartości typu unsigned int o 
    określoną liczbę miejsc w lewo. Na przykład, wywołanie obroc_l(x, 4) 
    przesunęłoby bity w wartości x o cztery miejsca w lewo, a bity, które 
    znalazły się poza lewą krawędzią pojawiłyby się ponownie z prawej 
    strony. Innymi słowy, bit wypchnięty z najbardziej znaczącego miejsca 
    zostaje umieszczony w miejscu najmniej znaczącym.
*/

#include <stdio.h>
#include <assert.h>

#define EIGHT_BITS 8

unsigned int rotate_left(unsigned int value, int n);

int main(void) {

    // Test 1
    unsigned int x1 = 10;
    printf("Przed: %u (0x%X)\n", x1, x1);
    unsigned int result1 = rotate_left(x1, 4);
    printf("Po:    %u (0x%X)\n", result1, result1);
    assert(result1 == 160);

    // Test 2
    unsigned int result2 = rotate_left(10, 36);
    assert(result2 == 160);

    // Test 3
    unsigned int result3 = rotate_left(4042322160, 8);
    assert(result3 == 4042322160);

    // Test 4
    unsigned int result4 = rotate_left(0, 8);
    assert(result4 == 0);

    return 0;
}

unsigned int rotate_left(unsigned int value, int n) {

    if(n < 0) {
        n = 0;
    }

    int bits = sizeof(unsigned int) * EIGHT_BITS; // (typowo 32 lub 64)
    n %= bits;

    return (value << n) | (value >> (bits - n));
}
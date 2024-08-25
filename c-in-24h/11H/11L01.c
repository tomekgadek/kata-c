/* 11L01.c: Odczytanie adresow zmiennych */

#include <stdio.h>

int main(void) {

    char c;
    int x;
    float y;
    
    printf("c: adres = 0x%p, zawartosc = %c\n", &c, c);
    printf("x: adres = 0x%p, zawartosc = %d\n", &x, x);
    printf("y: adres = 0x%p, zawartosc = %5.2f\n", &y, y);
   
    c = 'A';
    x = 7;
    y = 123.45;

    printf("c: adres = 0x%p, zawartosc = %c\n", &c, c);
    printf("x: adres = 0x%p, zawartosc = %d\n", &x, x);
    printf("y: adres = 0x%p, zawartosc = %5.2f\n", &y, y);

    return 0;
}

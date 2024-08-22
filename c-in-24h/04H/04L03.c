/* 04L03.c Wyprowadza numery kodu znakow ASCII */

#include <stdio.h>

int main(void) {

    char c1;
    char c2;

    c1 = 'A';
    c2 = 'a';

    printf("Wartosc numeryczna - kod ASCII litery A wynosi: %d\n", c1);
    printf("Wartosc numeryczna - kod ASCII litery a wynosi: %d\n", c2);

    return 0;
}

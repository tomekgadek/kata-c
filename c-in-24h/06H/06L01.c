/* 06L01.c: Arytmetyczne operatory przypisania */

#include <stdio.h>

int main(void) {

    int x, y, z; /* deklaracja 3 zmiennych calkowitych */

    x = 1;
    y = 3;
    z = 10;
    printf("Dane: x = %d y = %d oraz z = %d \n", x, y, z);

    x = x + y;
    printf("x = x + y przypisuje %d zmiennej x;\n", x);

    x = 1;
    x += y;
    printf("x += y przypisuje %d zmiennej x;\n", x);

    x = 1;
    z = z * x + y;
    printf("z = z * x + y przypisuje %d zmiennej z;\n", z);

    z = 10;
    z = z * (x + y);
    printf("z = z * (x + y) przypisuje %d zmiennej z;\n", z);

    z = 10;
    z *= x + y;
    printf("z *= x + y przypisuje %d zmiennej z.\n", z);

    return 0;
}

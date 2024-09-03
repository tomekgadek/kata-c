/* 20L03.c: Pomiar rozmiaru unii i struktury */

#include <stdio.h>
#include <string.h>

int main(void) {

    union u {
        double x;
        int y;
    } a_union;

    struct s {
        double x;
        int y;
    } a_struct;

    printf("Rozmiar double: %lu-bajtowe \n", sizeof(double));
    printf("Rozmiar int: %lu-bajtowe \n", sizeof(int));

    printf("Rozmiar unii a_union: %lu-bajtowe \n", sizeof(a_union));
    printf("Rozmiar struktury a_struct: %lu-bajtowe \n", sizeof(a_struct));

    return 0;
}

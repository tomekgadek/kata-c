/* 16L03.c: Dostep do tablic przy pomocy wskaznikow */

#include <stdio.h>

int main(void) {

    char str[] = "To jest napis - string !";
    char *p;
    int list[] = { 1, 2, 3, 4, 5 };
    int *pt;

    /* dostep do tablicy znakowej */
    p = str;
    printf("Przed zamiana, str zawiera: %s\n", str);
    printf("Przed zamiana, str[5] zawiera: %c\n", str[5]);
    *(p + 5) = 'S';
    printf("Po zamianie, str[5] zawiera: %c\n", str[5]);
    printf("Po zamianie, str zawiera: %s\n", str);

    /* dostep do tablicy numerycznej typu int */
    pt = list;
    printf("Przed zmana, list[2] zawiera: %d\n", list[2]);
    *(pt + 2) = -3;
    printf("Po zmanie, list[2] zawiera: %d\n", list[2]);

    return 0;
}

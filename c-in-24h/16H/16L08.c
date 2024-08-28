/* 16L08.c: Wskazanie funkcji */

#include <stdio.h>

/* deklaracja funkcji */
int strPrint(char *str);

int main(void) {

    char str[23] = "Pointing to a function.";   /* tablica znakowa - lancuch znakow */
    int (*ptr)(char *str);                      /* deklaracja wskaznika */

    ptr = strPrint;                             /* inicjowanie wskaznika do funkcji */
    if(!(*ptr)(str))
        printf("Done!\n");                      /* wykonane */

    return 0;
}

int strPrint(char *str) {

    printf("%s\n", str);
    return 0;
}

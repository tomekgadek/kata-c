/* 13L03.c: Kopiowanie lancuchow */

#include <stdio.h>
#include <string.h>

int main(void) {

    char str1[] = "Copy a string";
    char str2[15];
    char str3[15];
    int i;

    /* przy pomocy strcpy() */
    strcpy(str2, str1);

    /* bez uzycia strcpy() */
    for(i = 0; str1[i]; i++) {
        str3[i] = str1[i];
    }
    str3[i]='\0';

    /* Drukowanie zawartosci str2 oraz str3 */
    printf("Zawartosc str2: %s\n", str2);
    printf("Zawartosc str3: %s\n", str3);

    return 0;
}

/* 13L04.c: Zastosowanie funkcji gets() i puts() */

#include <stdio.h>

int main(void) {

    char str[80];
    int i;

    printf("Wpisz lancuch do maks. 80 znakow:\n");
    gets(str);

    i = 0;
    while(str[i]) {

        if((str[i] >= 97) && (str[i] <= 122))
            str[i] -= 32; /* zamiana liter malych na duze */
        ++i;
    }

    printf("Wprowadzony tekst byl taki: (DUZE LITERY):\n");
    puts(str);

    return 0;
}

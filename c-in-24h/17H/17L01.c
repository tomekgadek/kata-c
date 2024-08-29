/* 17L01.c: Zastosowanie funkcji malloc() */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* deklaracja funkcji kopiujacej stringi */
void strCopy(char *str1, char *str2);

/* poczatek funkcji main() */
int main(void) {

    char str[] = "Zastosowanie malloc() do przyporzatkowania pamieci";
    char *ptr_str;
    int termination;

    /* wywolanie malloc() */
    ptr_str = malloc(strlen(str) + 1);
    if(ptr_str != NULL) {
        strCopy(str,ptr_str);
        printf("Lancuch wskazany przez wskaznik ptr_str to: \n%s\n", ptr_str);
        termination = 0;
    } else {
        printf("Funkcja malloc() zwrocila pusty wskaznik\n");
        termination = 1;
    }

    return termination;
}

void strCopy(char *str1, char *str2) {
    int i;
    for(i = 0; str1[i]; i++)
        str2[i] = str1[i];
    str2[i] = '\0';
}

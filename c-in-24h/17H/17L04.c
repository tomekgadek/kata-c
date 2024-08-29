/* 17L04.c: Zastosowanie funkcji realloc(); */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* deklaracja funkcji */
void strCopy(char *str1, char *str2);

/* poczatek funkcji main() */
int main(void) {

    char *str[4] = {
        "* Kim sa Twoi kunkurenci?",
        "* Kim beda Twoi przysli klienci?",
        "* Czym wyrozni sie Twoj produkt sposrod konkurencji?",
        "* Jak duza czesc rynku zamierzasz objac?\n"
    };

    char *ptr;
    int i;

    int termination = 0;

    ptr = malloc((strlen(str[0]) + 1) * sizeof(char));
    if(ptr == NULL) {

        printf("Blad malloc(). Koniec programu. \n");
        termination = 1;
    } else {

        strCopy(str[0], ptr);
        printf("%s\n",ptr);
        for(i = 1; i < 4; i++) {
            ptr = realloc(ptr, (strlen(str[i])+1) * sizeof(char));
            if(ptr == NULL) {
                
                printf("Blad realloc(). Koniec programu. \n");
                termination = 1;
                break;
            } else {

                strCopy(str[i], ptr);
                printf("%s\n", ptr);
            }
        }
    }
    
    free(ptr);

    return termination;
}

void strCopy(char *str1, char *str2) {
    int i;

    for(i = 0; str1[i]; i++)
        str2[i] = str1[i];
    str2[i] = '\0';
}

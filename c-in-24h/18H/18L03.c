/* 18L03.c: Zastosowanie definiowania typu przy pomocy typedef */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum constans { 
    ROZMIAR = 3, 
    DELTA = 'a'-'A'
};

typedef char *STRING[ROZMIAR];
typedef char *PTR_STR;
typedef char BIT8;
typedef int BIT16;

void convert2Upper(PTR_STR str1, PTR_STR str2);

int main(void) {

    STRING str;
    STRING tekst = {
        "Lubie Graphisoft.",
        "Lubie recognite.",
        "Lubie edytor Lexikon97."
    };

    BIT16 i;
    BIT16 term = 0;

    for(i = 0; i < ROZMIAR; i++) {

        str[i] = malloc((strlen(tekst[i]) + 1) * sizeof(BIT8));
        if(str[i] == NULL) {

            printf("malloc() - blad. Koniec programu. \n");
            term = 1;
            break;
        }
        
        convert2Upper(tekst[i], str[i]);
        printf("%s\n", tekst[i]);
    }

    for(i = 0; i < ROZMIAR; i++) {

        printf("\n%s", str[i]);
        free(str[i]);
    }

    printf("\n");

    return term;
}

void convert2Upper(PTR_STR str1, PTR_STR str2) {

    BIT16 i;

    for(i = 0; str1[i]; i++) {

        if((str1[i] >= 'a') && (str1[i] <= 'z'))
            str2[i] = str1[i] - DELTA;
        else
            str2[i] = str1[i];
    }

    str2[i]='\0';
}

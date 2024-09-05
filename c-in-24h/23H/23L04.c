/* 23L04.c: Zagniezdzenie #if */

#include <stdio.h>

/* makrodefinicje */
#define ZERO 0
#define JEDEN 1
#define DWA (JEDEN + JEDEN)
#define TRZY (JEDEN + DWA)
#define TEST_1 JEDEN
#define TEST_2 DWA
#define TEST_3 TRZY
#define MAX_NUM TRZY
#define NO_ERROR ZERO

/* deklaracja funkcji */
void strPrint(char ** , int); /* nazwy formalne mozna pominac */

/* poczatek funkcji main() */
int main(void) {

    char *str[MAX_NUM] = {
        "Juz sam wybor punktu widzenia",
        "jest wyznacznikiem kultury.",
        "--- napisal: O. Gasset"
    };

    #if TEST_1 == 1
        #if TEST_2 == 2
            #if TEST_3 == 3
                strPrint(str, MAX_NUM);
            #else
                strPrint(str, MAX_NUM - JEDEN);
            #endif
        #else
            strPrint(str, MAX_NUM - DWA);
        #endif
    #else
        printf("Brak makra TEST. \n");
    #endif

    return NO_ERROR;
}

/*definicja funkcji*/
void strPrint(char **ptr_s, int numer) {

    int i;

    for(i = 0; i < numer; i++) {
        printf("Zawartosc: %s \n", ptr_s[i]);
    }
}

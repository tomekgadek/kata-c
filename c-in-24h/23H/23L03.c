/* 23L03.c: Zastosowanie dyrektyw #if #elif #else */

#include <stdio.h>

#define C_LANG 'C'
#define B_LANG 'B'
#define NO_ERROR 0

int main(void) {

    #if C_LANG == 'C' && B_LANG == 'B'
        #undef C_LANG
        #define C_LANG "Znam jezyk C. \n"
        #undef B_LANG
        #define B_LANG "Znam takze BASIC. \n"
        printf("%s%s", C_LANG, B_LANG);
    #elif C_LANG == 'C'
        #undef C_LANG
        #define C_LANG "Znam tylko jezyk C. \n"
        printf("%s", C_LANG);
    #elif B_LANG == 'B'
        #undef B_LANG
        #define B_LANG "Znam tylko BASIC. \n"
        printf("%s",B_LANG);
    #else
        printf("Nie znam ani C ani BASIC-a. \n");
    #endif

    return NO_ERROR;
}

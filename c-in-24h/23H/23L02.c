/* 23L02.c: Zastosowanie #ifdef, #ifndef, #endif */

#include <stdio.h>

#define UPPER_CASE 0
#define NO_ERROR 0

int main(void) {

    #ifdef UPPER_CASE
        printf("TEN WIERSZ JEST DRUKOWANY, \n");
        printf("BO SYMBOL UPPER_CASE JEST ZDEFINIOWANY. \n");
    #endif
    #ifndef LOVER_CASE
        printf("\nTen wiersz jest drukowany, \n");
        printf("bo symbol LOVER_CASE nie jest zdefiniowany. \n");
    #endif

    return NO_ERROR;
}

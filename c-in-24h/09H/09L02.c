/* 09L02.c Zastosowanie modyfikatorow short oraz long */

#include <stdio.h>

int main(void) {

    printf("Rozmiar short int: %lu\n", sizeof(short int));
    printf("Rozmiar long int: %lu\n", sizeof(int));
    printf("Rozmiar float: %lu\n", sizeof(float));
    printf("Rozmiar double: %lu\n", sizeof(double));
    printf("Rozmiar long double: %lu\n", sizeof(long double));

    return 0;
}    
    
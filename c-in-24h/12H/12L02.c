/* 12L02.c: Calkowita wielkosc tablicy w bajtach */

#include <stdio.h>

int main(void) {

    int total_byte;
    int list_int[10];
    
    total_byte = sizeof(int) * 10;

    printf("Element typu int zajmuje %lu-bajty. \n", sizeof(int));
    printf("Cala tablica zajmuje %d-bajtow. \n", total_byte);
    printf("Adres pierwszego elementu tablicy: %p \n", &list_int[0]);
    printf("Adres ostatniego elementu tablicy: %p \n", &list_int[9]);

    return 0;
}

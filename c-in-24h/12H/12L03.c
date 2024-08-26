/* 12L03.c: Odwolanie sie do tablicy za posrednictwem wskaznika */

#include <stdio.h>

int main(void) {

    int *ptr_int;
    int list_int[10];
    int i;
    
    for(i = 0; i < 10; i++)
        list_int[i] = i + 1;

    ptr_int = list_int;

    printf("Adres startowy tablicy: %p \n", ptr_int);
    printf("Wartosc pierwszego elementu tablicy: %d\n", *ptr_int);
    ptr_int = &list_int[0];
    printf("Adres pierwszego elementu: %p \n", ptr_int);
    printf("Wartosc pierwszego elementu tablicy: %d \n", *ptr_int);
    

    return 0;
}

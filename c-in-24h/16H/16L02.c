/* 16L02.c: Odejmowanie wskaznikow */

#include <stdio.h>

int main(void) {

	int *ptr_int1, *ptr_int2;

    printf("Poczatkowy adres wskazywany przez: ptr_int1: %p\n", ptr_int1);
    ptr_int2 = ptr_int1 + 5;
    printf("Poczatkowy adres wskazywany przez: ptr_int2 = ptr_int1 + 5: %p\n", ptr_int2);
    printf("Odejmowanie wskaznikow: ptr_int2 - ptr_int1: %ld\n", ptr_int2 - ptr_int1);
    ptr_int2 = ptr_int1 - 5;
    printf("Adres wskazywany przez: ptr_int2 = ptr_int1 - 5: %p\n", ptr_int2);
    printf("Odejmowanie wskaznikow: ptr_int2 - ptr_int1: %ld\n", ptr_int2 - ptr_int1);

    return 0;
}

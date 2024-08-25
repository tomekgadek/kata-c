/* 11L04.c: Wiecej niz jeden wskaznik wskazuje na ten sam adres */

#include <stdio.h>

int main(void) {

    int x;
    int *ptr_1, *ptr_2, *ptr_3;

    x = 1234;

    printf("x: adres = 0x%p zawiera = %d\n", &x, x);
    ptr_1 = &x;
        printf("ptr_1: adres = 0x%p zawiera = 0x%p\n", &ptr_1, ptr_1);
        printf("*ptr_1 => %d\n", *ptr_1);
    ptr_2 = &x;
        printf("ptr_2: adres = 0x%p zawiera = 0x%p\n", &ptr_2, ptr_2);
        printf("*ptr_2=>%d\n", *ptr_2);
    ptr_3 = ptr_1;
        printf("ptr_3: adres = 0x%p zawiera = 0x%p\n", &ptr_3, ptr_3);
        printf("*ptr3 => %d\n", *ptr_3);

    return 0;
}

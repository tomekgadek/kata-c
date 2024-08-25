/* 11L02.c: Deklarowanie wskaznikow i przypisywanie im wartosci */

#include <stdio.h>

int main(void) {

    char c, *ptr1;
    int x, *ptr2;
    float y, *ptr3;

    c = 'A';
    x = 7;
    y = 123.45;
    
    printf("c: adres = 0x%p, zawiera = %c\n", &c, c);
    printf("x: adres = 0x%p, zawiera = %d\n", &x, x);
    printf("y: adres = 0x%p, zawiera = %5.2f\n", &y, y);

    ptr1 = &c;
        printf("ptr_c: adres = 0x%p, zawiera = 0x%p\n", &ptr1, ptr1);
        printf("*ptr_c => %c\n", *ptr1);
    ptr2 = &x;
        printf("ptr_x: adres = 0x%p, zawiera = 0x%p\n", &ptr2, ptr2);
        printf("*ptr_x => %d\n", *ptr2);
    ptr3 = &y;
        printf("ptr_y: adres = 0x%p, zawiera = 0x%p\n", &ptr3, ptr3);
        printf("*ptr_y => %5.2f\n", *ptr3);

    return 0;
}

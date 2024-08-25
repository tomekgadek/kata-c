/* 11L03.c: Zmiana zawartosci zmiennej wskazywanej */

#include <stdio.h>

int main(void) {

    char c, *ptr_c;
    
    c = 'A';
    printf("c: adres 0x%p zawiera: %c\n", &c, c);
    ptr_c = &c;
        printf("ptr_c: adres 0x%p zawiera: 0x%p\n", &ptr_c, ptr_c);
        printf("*ptr_c => %c\n", *ptr_c);
    *ptr_c = 'B';
        printf("ptr_c: adres 0x%p zawiera: 0x%p\n", &ptr_c, ptr_c);
        printf("*ptr_c => %c\n", *ptr_c);
    
    printf("c: adres 0x%p zawiera: %c\n", &c, c);

    return 0;
}

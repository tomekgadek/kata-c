/* 16L01.c: Arytmetyka wskaznikow */

#include <stdio.h>

int main(void) {

    char *ptr_ch;
    int *ptr_int;
    double *ptr_db;

    puts("Przesuwamy pointer char ptr_ch - skok 1 bajt");
    printf("Biezaca pozycja pointera ptr_ch: %p\n", ptr_ch);
    printf("Pozycja po (ptr_ch + 1): %p\n", ptr_ch + 1);
    printf("Pozycja po (ptr_ch + 2): %p\n", ptr_ch + 2);
    printf("Pozycja po (ptr_ch - 1): %p\n", ptr_ch - 1);
    printf("Adres wskazany po (ptr_ch - 2): %p\n", ptr_ch - 2);
    puts("Teraz przesuwamy wskaznik int ptr_int - skok o 4 bajty");
    printf("Biezaca pozycja pointera ptr_int: %p\n", ptr_int);
    printf("Pozycja po (ptr_int + 1): %p\n", ptr_int + 1);
    printf("Pozycja po (ptr_int + 2): %p\n", ptr_int + 2);
    printf("Pozycja po (ptr_int - 1): %p\n", ptr_int - 1);
    printf("Pozycja po (ptr_int - 2): %p\n", ptr_int - 2);
    puts("Teraz przesuwamy wskaznik double ptr_db - skok o 8 bajtow");
    printf("Biezaca pozycja pointera ptr_db: %p\n", ptr_db);
    printf("Pozycja po (ptr_db + 1): %p\n", ptr_db + 1);
    printf("Pozycja po (ptr_db + 2): %p\n", ptr_db + 2);
    printf("Pozycja po (ptr_db - 1): %p\n", ptr_db - 1);
    printf("Pozycja po (ptr_db - 2): %p\n", ptr_db - 2);

    return 0;
}

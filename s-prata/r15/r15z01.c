/*
    r15.z01.c: Funkcja przetwarzająca łańcuch binarny na wartość liczbową

    1. Napisz funkcję, która przetwarza łańcuch binarny na wartość liczbową.
    Na przykład, jeśli mamy deklarację
    ```c
    char * wbin = "01001001";
    ```
    to po przekazaniu zmiennej `wbi` jako argumentu do funkcji zwraca wartość
    całkowitą `73`.
*/

#include <stdio.h>
#include <assert.h>

int bin_to_dec(const char *);

int main(void) {

    assert(bin_to_dec("01001001") == 73);
    assert(bin_to_dec("111") == 7);
    assert(bin_to_dec("100000") == 32);
    assert(bin_to_dec("00000000") == 0);
    assert(bin_to_dec("00000001") == 1);

    printf("01001001 to %d. \n", bin_to_dec("01001001"));

    return 0;
}

int bin_to_dec(const char *bin) {

    int value = 0;

    for(int i = 0; i < bin[i] != '\0'; i++) {
        value <<= 1;
        value += bin[i] - '0';
    }

    return value;
}
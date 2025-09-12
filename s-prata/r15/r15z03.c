/*
    r15z03.c: Program, który liczy ilość bitów włączonych w liczbie całkowitej

    3. Napisz funkcję, która przyjmuje argument typu `int`, a następnie zwraca
    ilość bitów, które są w nim włączone.
*/

#include <stdio.h>

int count_set_bits(int n);

int main(void) {

    printf("Liczba bitow wlaczonych w 7: %d \n", count_set_bits(7));
    printf("Liczba bitow wlaczonych w 8: %d \n", count_set_bits(8));
    printf("Liczba bitow wlaczonych w 0: %d \n", count_set_bits(0));
    printf("Liczba bitow wlaczonych w 3: %d \n", count_set_bits(3));

    return 0;
}

int count_set_bits(int n) {

    int count = 0;
    for( ; n != 0; n >>= 1) {
        count += n & 1;
    }

    return count;
}

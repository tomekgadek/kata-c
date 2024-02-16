/*
    Program potrafi zamienić wartości pomiędzy zmiennymi bez użycia zmiennej tymczasowej.
*/

#include <stdio.h>

/**
 * Odpowiada za zmianę wartości zmiennych bez użycia zmiennej tymczasowej (XOR).
 * 
 * @param param_a Wskaźnik do pierwszego parametru.
 * @param param_b Wskaźnik do drugiego patametru.
 *
 */
void swap(int * param_a, int * param_b);

int main(void) {

    int a = 1;
    int b = 2;

    printf("Before: a = %d, b = %d \n", a, b);
    swap(&a, &b);
    printf("After : a = %d, b = %d \n", a, b);

    return 0;
}

void swap(int * param_a, int * param_b) {

    *param_a ^= *param_b;
    *param_b ^= *param_a;
    *param_a ^= *param_b;
}

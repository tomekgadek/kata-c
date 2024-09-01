/* 18L04.c: Rekurencja funkcji */

#include <stdio.h>

enum con {
    MIN_NUM = 0,
    MAX_NUM=100
};

/* deklaracja funkcji */
int fRecur(int n);

int main(void) {

    int i, sum1 = 0, sum2 = 0;

    for(i = 1; i <= MAX_NUM; i++)
        sum1 += i;

    printf("Wartosc sum1 wynosi: %d\n", sum1);
    sum2 = fRecur(MAX_NUM);
    printf("Funkcja fRecur zwraca wartosc: %d\n", sum2);

    return 0;
}

/* definicja funkcji rekursywnej */
int fRecur(int n) {
    if(n == MIN_NUM)
        return 0;
    
    return fRecur(n - 1) + n;
}

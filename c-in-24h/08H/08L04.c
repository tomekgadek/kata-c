/* 08L04.c: Zastosowanie operatora negacji logicznej ! */

#include <stdio.h>

int main(void) {

    int num = 7;
    
    printf("Dana jest zmienna num o wartosci 7\n");
    printf("!(num < 7) zwraca %d\n", !(num < 7));
    printf("!(num > 7) zwraca %d\n", !(num > 7));
    printf("!(num == 7) zwraca %d\n", !(num == 7));

    return 0;
}

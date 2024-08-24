/* 08L02.c: Zastosowanie operatora iloczynu logicznego AND - && */

#include <stdio.h>

int main(void) {

    int num = 0;
    printf("Operator && zwraca: %d\n", (num % 2 == 0) && (num % 3 == 0));
    num = 2;
    printf("Operator && zwraca: %d\n", (num % 2 == 0) && (num % 3 == 0));
    num = 3;
    printf("Operator && zwraca: %d\n", (num % 2 == 0) && (num % 3 == 0));
    num = 6;
    printf("Operator && zwraca: %d\n", (num % 2 == 0) && (num % 3 == 0));

    return 0;
}

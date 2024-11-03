/*
    array-condition.c: PASTAB2 - Warunek w tablicy

    Zadanie: https://pl.spoj.com/problems/PASTAB2/

    Kompilacja oraz uruchomienie programu: gcc array-condition.c && ./a.out < ./tests/array-condition.txt
*/
#include <stdio.h>
#include <stdlib.h>

void print_less_digits(long int cmp_value, long int digits[], long int size);
void print_greater_digits(long int cmp_value, long int digits[], long int size);

int main(void) {

    int digits_size = 0;
    scanf("%d", &digits_size);

    long int *digits = (long int *)calloc(digits_size, sizeof(long int));
    if(digits == NULL) {
        return 1;
    }

    for(int i = 0; i < digits_size; i++) {
        scanf("%ld", &digits[i]);
    }

    char sign = '_';
    while((sign = getchar()) == '\n');

    long int comparison_value = 0;
    scanf("%ld", &comparison_value);

    switch(sign) {
        case '>':
            print_greater_digits(comparison_value, digits, digits_size);
            break;

        case '<':
            print_less_digits(comparison_value, digits, digits_size);
            break;
    }

    free(digits);
    return 0;
}

void print_less_digits(long int cmp_value, long int digits[], long int size) {
    for(int i = 0; i < size; i++) {
        if(digits[i] < cmp_value) {
            printf("%ld \n", digits[i]);
        }
    }
}

void print_greater_digits(long int cmp_value, long int digits[], long int size) {

    for(int i = 0; i < size; i++) {
        if(digits[i] > cmp_value) {
            printf("%ld \n", digits[i]);
        }
    }
}

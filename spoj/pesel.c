/*
    pesel.c: JPESEL - Pesel

    Zadanie: https://pl.spoj.com/problems/JPESEL/

    Kompilacja oraz uruchomienie programu: gcc pesel.c && ./a.out < ./tests/pesel-tests.txt
*/
#include <stdio.h>
#include <stdlib.h>

#define DIGIT_SIZE 2
#define PESEL_SIZE 11
#define PESEL_CORRECT   'D'
#define PESEL_INCORRECT 'N'

int main(void) {

    char pesel[PESEL_SIZE+1];
    char digit[DIGIT_SIZE] = "0";
    int pesel_consts[PESEL_SIZE] = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1 };
    int data_size = 0;

    scanf("%d", &data_size);

    for(int check_digit = 0; data_size > 0; data_size--) {

        scanf("%s", pesel);

        check_digit = 0;
        for(int i = 0; i < PESEL_SIZE; i++) {
            digit[0] = pesel[i];
            check_digit += (pesel_consts[i] * atoi(digit));
        }

        if(check_digit > 0) {
            putchar(check_digit % 10 == 0 ? PESEL_CORRECT : PESEL_INCORRECT);
        } else {
            putchar(PESEL_INCORRECT);
        }

        putchar('\n');
    }

    return 0;
}

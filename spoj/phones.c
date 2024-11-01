/*
    phones.c: PTWPZ073 - PTwPZ Telefony

    Zadanie: https://pl.spoj.com/problems/PTWPZ073/

    Kompilacja oraz uruchomienie programu: gcc phones.c && ./a.out < ./tests/phones-tests.txt
*/
#include <stdio.h>

#define TXT_SIZE 21

int convert_to_number(char);

int main(void) {

    int number_of_tests = 0;
    scanf("%d", &number_of_tests);

    char message[TXT_SIZE + 1];

    for(int i = 0; i < number_of_tests; i++) {

        scanf("%s", message);

        for(int m = 0; message[m] != '\0'; m++) {
            printf("%d", convert_to_number(message[m]));
        }

        putchar('\n');
    }

    return 0;
}

int convert_to_number(char button_sign) {

    const char FIRST_SIGN = 'A';

    const int PHONE_DIGITS[] = {
        2, 2, 2,
        3, 3, 3,
        4, 4, 4,
        5, 5, 5,
        6, 6, 6,
        7, 7, 7, 7,
        8, 8, 8,
        9, 9, 9, 9
    };

    return PHONE_DIGITS[button_sign - FIRST_SIGN];
}

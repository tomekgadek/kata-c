/*
    gronsfeld-cipher.c: WI_SZYFR - Szyfr Gronsfelda

    Zadanie: https://pl.spoj.com/problems/WI_SZYFR/

    Kompilacja oraz uruchomienie programu: gcc gronsfeld-cipher.c && ./a.out < ./tests/gronsfeld-cipher-tests.txt
*/
#include <stdio.h>
#include <stdlib.h>

#define OPTION_SIZE 9 + 1          // 9 ... '\0'
#define CODE_SIZE   1000000000 + 1 // 1000000000 ... '\0'

int key_to_digit(char);
char decode(char, int);
char encode(char, int);

int main(void) {

    char option[OPTION_SIZE];
    char *key = (char *) calloc(CODE_SIZE, sizeof(char));

    scanf("%s %s", option, key);

    while(getchar() != '\n');

    char sign = '?';
    for(int idx_key; (sign = getc(stdin)) != '\n'; idx_key++) {

        if(key[idx_key] == '\0') {
            idx_key = 0;
        }

        int shift = key_to_digit(key[idx_key]);

        switch(option[0]) {

            case 'S': // S jak SZYFRUJ
                putchar(encode(sign, shift));
                break;

            case 'D': // D jak DESZYFRUJ
                putchar(decode(sign, shift));
                break;
        };
    }

    free(key);

    putchar('\n');

    return 0;
}

int key_to_digit(char sign) {
    return sign - '0';
}

char decode(char sign, int shift) {

    char new_sign = (sign - shift);

    if(new_sign < 'A') {
        new_sign = 'Z' - ('A' - new_sign) + 1;
    }

    return new_sign;
}

char encode(char sign, int shift) {

    char new_sign = (sign + shift);

    if(new_sign > 'Z') {
        new_sign = 'A' + (new_sign - 'Z') - 1;
    }

    return new_sign;
}

/* 05L03.c: Funkcja putc() wysyla znak na ekran */

#include <stdio.h>

int main(void) {

    int kod_znaku;

    kod_znaku = 65; /*Kod ASCII litery A*/
    printf("Znak o kodzie ASCII 65 to: \n");
    putc(kod_znaku, stdout);

    return 0;
}

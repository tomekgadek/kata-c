/*
    r08z01.c: Zliczanie znaków

    1. Napisz program, który zlicza znaki (wpisywane lub pobierane z pliku) aż 
    do wystąpienia końca pliku.
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    printf("Wprowadz znaki (CTRL+D to koniec): \n");

    int char_counter = 0;
    char character = '?';
    while((character = getchar()) != EOF) {

        if(isalpha(character)) {
            char_counter++;
        }
    }

    printf("Wprowadzono %d znakow. \n", char_counter);

    return 0;
}

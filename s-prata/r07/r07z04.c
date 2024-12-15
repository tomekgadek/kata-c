/*
    r07z04.c: Praktyczne zastosowanie instrukcji if-else

    4. Korzystając z instrukcji 'if else', napisz program, który odczytuje 
    dane wejściowe do znaku '#', zastępuje każdą kropkę wykrzyknikiem, a 
    każdy wykrzyknik — dwoma wykrzyknikami, oraz wyświetla liczbę zmian
    jaką wykonał.
*/

#include <stdio.h>

int main(void) {

    printf("Wprowadz tekst: \n");

    int changes_counter = 0;

    for(char input_char = '?'; (input_char = getchar()) != '#'; ) {

        if(input_char == '.') {

            putchar('!');
            changes_counter++;
        } else if(input_char == '!') {

            putchar('!');
            putchar('!');
            changes_counter++;
        } else {
            putchar(input_char);
        }
    }

    printf("\nLiczba zmian: %d \n", changes_counter);

    return 0;
}

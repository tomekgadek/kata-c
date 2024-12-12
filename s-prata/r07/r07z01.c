/*
    r07z01.c: Zliczanie znaków

    1. Napisz program, który odczytuje dane wejściowe aż do napotkania znaku
    '#', a następnie wyświetla informację o liczbie odczytanych odstępów, 
    znaków nowej linii i wszystkich innych znaków.
*/

#include <stdio.h>

int main(void) {

    int input_char = '?';

    int new_line_counter = 0;
    int space_and_tab_counter = 0;
    int other_characters_counter = 0;

    printf("Wprowadz tekst: \n");

    while((input_char = getchar()) != '#') {

        switch(input_char) {

            case '\n':
                new_line_counter++;
                break;
            case ' ':
            case '\t':
                space_and_tab_counter++;
                break;
            default:
                other_characters_counter++;
        }
    }

    printf("Liczba znakow nowej linii:   %d. \n", new_line_counter);
    printf("Liczba odczytanych odstepow: %d. \n", space_and_tab_counter);
    printf("Liczba pozostalych znakow:   %d. \n", other_characters_counter);

    return 0;
}

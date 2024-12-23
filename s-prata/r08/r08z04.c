/*
    r08z03.c: Średnia liczba liter w słowie

    4. Napisz program, który odczytuje dane do napotkania końca pliku 
    i wyświetla średnią liczbę liter w słowie. Pamiętaj, że do liter nie można 
    zaliczyć znaków niedrukowanych. Ściśle rzecz biorąc, nie należałoby 
    również zliczać znaków przestankowych, ale nie musisz się tym przejmować. 
    (Jeśli jednak chcesz się tym przejmować, możesz skorzystać z funkcji 
    'ispunct()' z rodziny 'ctype.h').
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    char input_char = '?';

    int char_counter = 0;
    int word_counter = 0;

    bool char_white_marker = false;

    printf("Podaj tekst: \n");

    do {

        input_char = getchar();

        if(isalpha(input_char)) {
            char_white_marker = false;
            char_counter++;
        }

        if((isspace(input_char) || input_char == EOF) && !char_white_marker) {
            char_white_marker = true;
            word_counter++;
        }

    } while(input_char != EOF);

    printf("\nSrednia liczba liter w slowie wynosi: %.2f. \n", 
        char_counter/(float)word_counter);

    return 0;
}

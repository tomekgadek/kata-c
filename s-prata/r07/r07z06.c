/*
    r07z06.c: Ile razy wystąpuł ciąg "an"

    6. Napisz program, który wczytuje tekst wejściowy do znaku '#' i zwraca 
    informację o liczbie razy, jaka występuje w nim ciąg "an".
    Uwaga: 
        Program będzie musiał 'pamiętać' zarówno bieżący, jak i poprzedni znak.
    
    Do jego przetestowania możesz użyć zdania "Banany staniały".
*/

#include <stdio.h>

int main(void) {

    char input_char_left = '?';
    char input_char_right = '?';

    printf("Wprowadz tekst: \n");

    int an_counter = 0;
    while((input_char_right = getchar()) != '#') {

        if(input_char_left == 'a' && input_char_right == 'n') {
            an_counter += 1;
        }

        input_char_left = input_char_right;
    }

    printf("\nCiag \'an\' wystapil %d raz(y). \n", an_counter);

    return 0;
}

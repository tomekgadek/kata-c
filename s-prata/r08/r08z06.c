/*
    r08z06.c: Funkcja, która zwraca pierwszy napotkany znak drukowany

    6. Zmodyfikuj funkcję 'pobierz_pierwszy()' z listingu 8.8 tak, aby zwracała 
    ona pierwszy napotkany znak drukowany. Przetestuj ją w prostym programie.
*/

#include <stdio.h>
#include <ctype.h>

char pobierz_pierwszy(void);

int main(void) {

    printf("Wprowadz tekst: ");
    char first_letter = pobierz_pierwszy();

    printf("Pierwszy znak drukowany to: %c. \n", first_letter);

    return 0;
}

char pobierz_pierwszy(void) {

    char character = ' ';

    while((character = getchar()) != '\n') {

        if(!isspace(character)) {
            break;
        }
    }

    return character;
}

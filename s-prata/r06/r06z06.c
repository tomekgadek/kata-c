/*
    r06z06.c: Wspak

    6. Napisz program, który wczytuje pojedyncze słowo do tablicy 
    znakowej, a następnie wyświetla je wspak.
    Wskazówka: Użyj funkcji 'strlen()' do obliczenia indeksu ostatniego 
    znaku w tablicy (patrz Rozdzial 4 "Łańcuchy znakowe i formatowane
    wejście / wyjście").
*/

#include <stdio.h>
#include <string.h>

#define STR_SIZE 20 + 1

int main(void) {

    char message[STR_SIZE];

    printf("Podaj slowo: ");
    scanf("%s", message);

    int last_idx = strlen(message) - 1;

    printf("size = %d \n", last_idx);

    for(int i = last_idx; i >= 0; --i) {

        putchar(message[i]);
    }

    putchar('\n');

    return 0;
}

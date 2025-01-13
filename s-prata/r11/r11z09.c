/*
    r11z09.c: Funkcja, która usuwa odstępy z łańcucha

    9. Napisz funkcję, która pobiera łańcuch i usuwa z niego odstępy. Wypróbuj 
    ją w programie, który odczytuje wiersze za pomocą pętli i kończy działanie 
    po wpisaniu pustej linii. Program powinien stosować funkcję do każdego 
    wpisanego wiersza i wyświetlać wynik.
*/

#include <stdio.h>

#define LINE_SIZE 1024

char *remove_spaces(char *);

int main(void) {

    char line[LINE_SIZE];

    fputs("Wprowadz tekst: \n", stdout);
    while(fgets(line, LINE_SIZE, stdin) != NULL && line[1] != '\0') {

        fputs(remove_spaces(line), stdout);
    }

    fputs("Koniec. \n", stdout);

    return 0;
}

char *remove_spaces(char *line) {

    int i = 0, j = 0;

    while(line[i] != '\0') {

        line[j] = line[i];
        if(line[j] != ' ') {
            j++;
        }

        i++;
    }

    line[j] = '\0';

    return line;
}

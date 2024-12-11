/*
    r06z12.c: Odczytaj wiersz danych i wyświetl go wspak

    12. Napisz program, który odczytuje jeden wiersz danych wejściowych, a 
    następnie wyświetla go wspak. Pamiętaj, że do pobrania jednego znaku możesz 
    użyć funkcji `scanf()` ze specyfikacją '%c' oraz że wciśnięcie klawisza 
    Enter generuje znak nowej linii ('\n').
*/

#include <stdio.h>
#include <string.h>

const int ARRAY_SIZE = 50 + 1;

int main(void) {

    char line[ARRAY_SIZE];

    printf("Wprowadz tekst: ");

    int i = 0;
    do {
        scanf("%c", &line[i]);

    } while(line[i++] != '\n');

    line[--i] = '\0';

    for(int i = strlen(line) - 1; i >= 0; --i) {

        printf("%c", line[i]);
    }

    printf("\n");

    return 0;
}

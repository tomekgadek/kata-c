/*
    r11z03.c: Funkcja pobierająca pierwsze słowo

    3. Zaprojektuj funkcję, która pobiera z danych wejściowych pierwsze słowo 
    i porzuca resztę wiersza. Za słowo możesz uznać ciąg znaków nie 
    zawierający odstępów, tabulatorów lub znaków nowej linii.
*/

#include <stdio.h>

#define ARRAY_SIZE 10 + 1

void get_word(char *, int);

int main(void) {

    char message[ARRAY_SIZE];

    printf("Wprowadz tekst: ");
    get_word(message, ARRAY_SIZE);

    printf("Oto rezultat: ");
    fputs(message, stdout);

    printf("\n");

    return 0;
}

void get_word(char *message, int limit) {

    char character = '?';
    int i = 0;

    while(i < limit - 1) {
        char character = getchar();
        
        if(character == ' ' || character == '\t' || character == '\n') {
            break;
        }

        message[i] = character;
        i += 1;
    }

    message[i] = '\0';
}

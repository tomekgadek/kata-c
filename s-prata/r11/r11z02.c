/*
    r11z02.c: Funkcja pobierająca n znaków (modyfikacja)

    2. Zmodyfikuj funkcję z ćwiczenia 1 tak, aby kończyła działanie po odczytaniu 
    n znaków lub po napotkaniu pierwszego odstępu, tabulatora lub znaku nowej 
    linii. (Nie korzystaj z funkcji scanf().)
*/

#include <stdio.h>

#define ARRAY_SIZE 256

void getchar_n(char *, int);

int main(void) {

    char message[ARRAY_SIZE];

    printf("Wprowadz tekst: ");
    getchar_n(message, 5);

    printf("\nOto rezultat: ");
    fputs(message, stdout);

    printf("\n");

    return 0;
}

void getchar_n(char *message, int n) {

    char character = '?';
    int i = 0;

    while(i < n) {
        char character = getchar();
        
        if(character == EOF || character == ' ' || character == '\t' || character == '\n') {
            break;
        }

        message[i] = character;
        i += 1;
    }

    message[i] = '\0';
}

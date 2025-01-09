/*
    r11z01.c: Funkcja pobierająca n znaków

    1. Zaprojektuj funkcję, która pobiera z klawiatury najbliższe n znaków, 
    włącznie z odstępami, tabulatorami i znakami nowej linii.
*/

#include <stdio.h>

#define ARRAY_SIZE 256

void getchar_n(char *, int);

int main(void) {

    char message[ARRAY_SIZE];

    printf("Wprowadz tekst: ");
    getchar_n(message, 3);

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
        
        if(character == EOF) {
            break;
        }

        message[i] = character;
        i += 1;
    }

    message[i] = '\0';
}

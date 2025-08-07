/*
    r12z04.c: Zastąpienie argumentów wiersza poleceń interaktywnym wejściem danych

    4. Wadą programów korzystających z argumentów wiersza poleceń jest to, iż 
    wymagają one od użytkownika znajomości zasad ich prawidłowego użycia. 
    Zmień program z listingu 12.2 tak, aby zamiast przyjmować argumenty, 
    umożliwiał on wpisanie potrzebnych informacji w sposób interaktywny.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *we, *wy;
    int ch;
    char nazwa[40];
    int licznik = 0;
    char *wsk;

    printf("Podaj nazwe pliku do kompresji: ");
    scanf("%s", &nazwa[0]);

    if ((we = fopen(nazwa, "r")) == NULL) {
        fprintf(stderr, "Nie moglem otworzyc pliku %s. \n", nazwa);
        exit(EXIT_FAILURE);
    }

    wsk = strstr(nazwa, ".");
    *wsk = '\0';
    strcat(nazwa, ".red");

    if ((wy = fopen(nazwa, "w")) == NULL) {
        fprintf(stderr, "Nie mozna utworzyc pliku %s. \n", nazwa);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(we)) != EOF)
        if (licznik++ % 3 == 0)
            putc((char)ch, wy);

    if (fclose(we) != 0 || fclose(wy) != 0)
        fprintf(stderr, "Blad przy zamykaniu plikow. \n");

    return EXIT_SUCCESS;
}

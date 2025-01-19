/*
    r11z15.c: Praktyczne wykorzystanie wiersza poleceń

    15. Napisz program, który odczytuje dane do końca pliku i wyświetla je na 
    ekranie. Program powinien reagować na następujące argumenty 
    wiersza poleceń:
        -p wyświetlanie danych bez zmian
        -u zamiana wszystkich liter na duże
        -l zamiana wszystkich liter na male
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define DEFAULT_OPTION "-p"
#define UPPER_OPTION   "-u"
#define LOWER_OPTION   "-l"

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Podaj parametr podczas uruchamiania programu! \n");
        printf("./a.out -p wyswietla dane bez zmian. \n");
        printf("./a.out -u zamienia wszystkie litery na duze. \n");
        printf("./a.out -l zamienia wszystkie litery na male. \n");

        return 1;
    }

    printf("Podaj tekst: ");

    char *option = argv[1];
    char character = '?';
    while((character = getchar()) != EOF) {

        if(strcmp(option, DEFAULT_OPTION) == 0) {
            putchar(character);
        } else if(strcmp(option, UPPER_OPTION) == 0) {
            putchar(toupper(character));

        } else if(strcmp(option, LOWER_OPTION) == 0) {
            putchar(tolower(character));
        }
    }

    putchar('\n');

    return 0;
}

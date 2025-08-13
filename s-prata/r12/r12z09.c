/*
    r12z09.c: Wyszukiwanie łańcucha w pliku

    9. Napisz program, który przyjmuje dwa argumenty wiersza poleceń. Pierwszy 
    z nich jest łańcuchem, drugi – nazwą pliku. Program powinien następnie 
    przeszukać plik i wyświetlić wszystkie wiersze zawierające podany łańcuch. 
    (Ponieważ zadanie to wymaga przetwarzania łańcuchów, a nie znaków, użyj 
    funkcji fgets() zamiast getc(). Przeszukiwanie wiersza zrealizuj za pomocą 
    standardowej funkcji strstr(), opisanej krótko w Rozdziale 11.)
*/

#include <stdio.h>
#include <string.h>

#define LINE_SIZE 128

int main(int argc, char *argv[]) {

    if(argc != 3) {
        fprintf(stderr, "Sposob uzycia: %s lancuch nazwa_pliku \n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");

    if(file == NULL) {
        fprintf(stderr, "Nie moge otworzyc pliku %s. \n", argv[2]);
        return 2;
    }

    printf("Tekst \'%s\' znajduje sie w nastepujacych wierszach: \n", argv[1]);

    char line[LINE_SIZE];
    while (fgets(line, LINE_SIZE, file) != NULL) {
        if (strstr(line, argv[1]) != NULL) {
            fputs(line, stdout);
        }
    }

    putchar('\n');

    fclose(file);

    return 0;
}

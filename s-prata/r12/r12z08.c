/*
    r12z08.c: Interaktywny odczyt fragmentów pliku tekstowego

    8. Napisz program, który otwiera plik tekstowy o nazwie uzyskiwanej w 
    sposób interaktywny. Utwórz pętlę, umożliwiającą użytkownikowi podanie 
    położenia w pliku. Program powinien wyświetlić część pliku zawartą pomiędzy 
    podanym miejscem a najbliższym znakiem nowej linii. Sygnałem kończącym 
    program powinno być podanie przez użytkownika danych nienumerycznych.
*/

#include <stdio.h>

#define LABEL_SIZE 20

int main(void) {
    
    printf("Podaj nazwe oraz rozszerzenie swojego pliku: ");

    char filename[LABEL_SIZE];
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Nie moge otworzyc pliku %s. \n", filename);
        return 1;
    }

    fseek(file, 0L, SEEK_END);

    int end_pos = ftell(file);
    int set_pos = 0;

    char sign = ' ';

    printf("Podaj pozycje: ");
    while (scanf("%d", &set_pos) == 1 && set_pos >= 0 && set_pos < end_pos) {
        fseek(file, set_pos, SEEK_SET);

        while ((sign = getc(file)) != '\n' && sign != EOF) {

            putc(sign, stdout);    
        }

        printf("\nPodaj pozycje: ");
    }

    fclose(file);

    printf("\n");

    return 0;
}

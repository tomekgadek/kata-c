/*
    r12z10.c: Jak pozostawić znak ograniczający w buforze wejściowym?

    10. Napisz funkcję, która odczytuje z pliku jedno słowo, pozostawiając 
    znak ograniczający (tabulator, odstęp lub znak nowej linii) w buforze 
    wejściowym. Nie korzystaj z funkcji scanf() ani fscanf().
*/

#include <stdio.h>

int main(void) {

    FILE *file = fopen("static/search.txt", "r");

    if(file == NULL) {
        fprintf(stderr, "Nie otwarto pliku.");
        return 1;
    }

    printf("Odczytuje slowo z pliku: ");

    char sign = ' ';
    while ((sign = getc(file)) != EOF) {
        if (sign == '\n' || sign == '\t' || sign == ' ') {
            ungetc(sign, stdin);
            break;
        }

        putc(sign, stdout);
    }

    fclose(file);
    
    printf("\nKod znaku pozostawionego w buforze wejsciowym: %d. \n", fgetc(stdin));

    return 0;
}

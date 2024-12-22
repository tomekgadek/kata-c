/*
    r08z02.c: Znak oraz dziesiętny kod ASCII

    2. Napisz program, który odczytuje dane wejściowe do momentu napotkania 
    końca pliku i wyświetla każdy znak wraz z jego dziesiętnym kodem ASCII. 
    W jednym wierszu powinno znajdować się dziesięć par znak-kod, ale 
    odczytanie znaku nowej linii powinno pociągać za sobą rozpoczęcie 
    nowego wiersza. Znaki niedrukowane o kodach mniejszych niż kod spacji 
    powinny być traktowane w szczególny sposób. Jeśli znak jest tabulatorem 
    lub znakiem nowej linii, należy wyświetlić odpowiednio '\t' lub '\n'. 
    Inne znaki niedrukowane należy przedstawić w postaci znaków sterujących. 
    Na przykład, znak o kodzie 1 to Ctrl-A, co można zapisać jako '^A'. Zwróć 
    uwagę, że kod ASCII litery A jest o 64 większy niż kod znaku Ctrl-A. 
    Podobna zależność zachodzi dla innych znaków niedrukowanych.
*/

#include <stdio.h>

const int LINE_SIZE = 10;

int main(void) {

    char input_char = '?';
    int line_counter = 0;

    printf("Wprowadz tekst: \n");
    while((input_char = getchar()) != EOF) {

        line_counter++;

        if(input_char >= ' ' || input_char == 0) {
            
            printf("(%-2c - %3d)", input_char, input_char);
        } else if(input_char == '\n') {

            printf("(\\n - %3d) \n", input_char);
            line_counter = 0;
        } else if(input_char == '\t') {

            printf("(\\t- %3d)", input_char);
        } else {
            printf("(^%c - %3d)", input_char+64, input_char);
        }

        if(line_counter == LINE_SIZE) {
            line_counter = 0;
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}

/*
    r07z02.c: Wyświetlanie znaków w formacie znak-kod

    2. Napisz program, który odczytuje dane wejściowe aż do napotkania 
    znaku '#', a następnie wyświetla każdy wpisany znak wraz z jego dziesiętnym 
    kodem ASCII. W jednym wierszu powinno znajdować się osiem par znak-kod.
    
    Propozycja:
        Użyj licznika znaków i operatora modulo ('%') do wyświetlania znaku 
        nowej linii w co ósmym cyklu pętli.
*/

#include <stdio.h>

int main(void) {

    int input_char = '?';

    printf("Wprowadz tekst: \n");

    for(int i = 0; (input_char = getchar()) != '#'; i++) {

        if(i % 8 == 0) {
            putchar('\n');
        }

        printf("\'%c\'-%3d  ", input_char, input_char);
    }

    putchar('\n');

    return 0;
}

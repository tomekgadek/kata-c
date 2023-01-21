/*
    Zabawa, ktora polega na wprowadzaniu znakow z klawiatury. Jezeli wprowadzimy 'x' to
    program zostanie zatrzymany.
*/

#include <stdio.h>
#include <stdbool.h>

/**
 * Weryfikuje, czy podany znak to 'x'.
 *
 * @param sign znak wprowadzony przez uzytkownika.
 *
 * @return true - wprowadzony znak to 'x', false - wprowadzony znak to nie jest 'x'.
 */
bool is_terminate_program(char sign);

int main(void) {

    char sign = ' ';

    printf("Rozpocznij wprowadzanie znakow... \n");
    do {
        sign = getc(stdin);
        putc(sign, stdout);
    } while(!is_terminate_program(sign));

    printf("\n");
    printf("Koniec zabawy... \n");

    return 0;
}

bool is_terminate_program(char sign) {
    return sign == 'x';
}
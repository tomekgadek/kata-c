/*
    r02z05.c: Operacje na liczbie całkowitej

    5. Napisz program, który tworzy zmienną całkowitą o nazwie liczba (digit), nadaje 
    jej wartość 10, oblicza podwojoną i podniesioną do kwadratu wartość zmiennej 
    oraz wyświetla wszystkie trzy liczby odpowiednio je oznaczając.
*/

#include <stdio.h>

int main(void) {

    int digit = 10;
    int digit_x_2 = digit * 2;
    int digit_x_digit = digit * digit;

    printf("%i \n", digit);
    printf("%i x 2 = %i \n", digit, digit_x_2);
    printf("%i ^ 2 = %i \n", digit, digit_x_digit);

    return 0;
}

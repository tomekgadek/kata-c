/*
    r05z06.c: Liczba zmiennoprzecinkowa podniesiona do 3 potęgi

    6. Napisz program, który pobiera liczbę zmiennoprzecinkową i wyświetla ją 
    po podniesieniu do sześcianu. Do podniesienia liczby do sześcianu i jej 
    wyświetlenia użyj własnej funkcji. Wpisana wartość powinna zostać 
    przekazana jako parametr.
*/

#include <stdio.h>

void pow3(float);

int main(void) {

    float digit = 0.0f;

    printf("Podaj liczbe zmiennoprzecinkowa: ");
    scanf("%f", &digit);

    pow3(digit);

    return 0;
}

void pow3(float digit) {

    printf("%.2f^3 = %.2f \n", digit, (digit * digit * digit));
}

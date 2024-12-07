/*
    r06z07.c: Operacje na 2 liczbach zmiennoprzecinkowych

    7. Napisz program, który pobiera dwie liczby zmiennoprzecinkowe i wyświetla 
    wartość ich różnicy podzielonej przez ich iloczyn. Program powinien 
    odczytywać kolejne pary danych wejściowych aż do momentu, gdy użytkownik 
    wpisze wartość nie będącą liczbą.
*/

#include <stdio.h>

int main(void) {

    float digitA = 0.0f;
    float digitB = 0.0f;

    printf("Podaj 2 liczby zmiennoprzecinkowe ('q' = koniec): ");

    while(scanf("%f %f", &digitA, &digitB) == 2) {

        printf("(%.2f - %.2f)/(%.2f * %.2f) = %.2f \n",
            digitA, digitB, digitA, digitB, (digitA - digitB)/(digitA * digitB)
        );

        printf("Podaj 2 liczby zmiennoprzecinkowe ('q' = koniec): ");
    }

    printf("Koniec... \n");

    return 0;
}

/*
    r06z08.c: Operacje na 2 liczbach zmiennoprzecinkowych + funkcja

    8. Zmodyfikuj ćwiczenie 7 tak, aby program do obliczenia wyniku 
    wykorzystywał funkcję.
*/

#include <stdio.h>

float calc(float, float);

int main(void) {

    float digitA = 0.0f;
    float digitB = 0.0f;

    printf("Podaj 2 liczby zmiennoprzecinkowe ('q' = koniec): ");

    while(scanf("%f %f", &digitA, &digitB) == 2) {

        printf("(%.2f - %.2f)/(%.2f * %.2f) = %.2f \n",
            digitA, digitB, digitA, digitB, calc(digitA, digitB)
        );

        printf("Podaj 2 liczby zmiennoprzecinkowe ('q' = koniec): ");
    }

    printf("Koniec... \n");

    return 0;
}

float calc(float digitA, float digitB) {

    return (digitA - digitB)/(digitA * digitB);
}

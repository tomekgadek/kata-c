/* 15L03.c: Obsluga zmiennej liczby argumentow */

#include <stdio.h>
#include <stdarg.h>

double addDouble(int x, ...);

int main(void) {

    double d1 = 1.5;
    double d2 = 2.5;
    double d3 = 3.5;
    double d4 = 4.5;

    puts("Dodawanie zmiennej liczby argumentow.");
    printf("Dany jest argument d1: %2.1f\n", d1);
    printf("addDouble(1,d1) - wynik dodawania: %2.1f\n\n", addDouble(1,d1));
    printf("Dane sa argumenty: d1, d2: %2.1f i %2.1f\n", d1, d2);
    printf("addDouble(2, d1, d2) - wynik dodawania: %2.1f\n\n", addDouble(2, d1, d2));
    printf("Argumenty d1, d2, d3: %2.1f, %2.1f i %2.1f\n", d1, d2, d3);
    printf("Wynik addDouble(3, d1, d2, d3): %2.1f\n\n", addDouble(3, d1, d2, d3));
    printf("Argumenty d1, d2, d3, d4: %2.1f, %2.1f, %2.1f i %2.1f\n", d1, d2, d3, d4);
    printf("Wynik addDouble(4, d1, d2, d3, d4): %2.1f\n\n", addDouble(4, d1, d2, d3, d4));

    return 0;
}

double addDouble(int x, ...) {

    va_list lista;
    int i;
    double wynik = 0.0;

    printf("...z wnetrza funkcji, liczba argumentow: %d\n", x);
    va_start(lista, x);
    for(i = 0; i < x; i++)
        wynik += va_arg(lista, double);
    va_end(lista);

    return (wynik);
}

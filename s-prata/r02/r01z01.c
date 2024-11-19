/*
    r02z01.c: Program wypisujący na ekranie imię i nazwisko.

    1. Napisz program, wypisujący na ekranie Twoje imię i nazwisko: w jednym wierszu przy pomocy 
    jednego wywołania funkcji printf(), w dwóch osobnych wierszach przy pomocy jednego wywołania printf() 
    oraz w jednym wierszu przy użyciu dwóch wywołań printf(). Dane wyjściowe powinny wyglądać następująco 
    (z wyjątkiem imienia i nazwiska):

    Hans Kloss     Pierwsza instrukcja pisania
    Hans           Druga instrukcja pisania
    Kloss          Wciąż druga instrukcja pisania
    Hans Kloss     Trzecia i czwarta instrukcja pisania
*/

#include <stdio.h>

int main(void) {

    printf("Hans Kloss     Pierwsza instrukcja pisania \n");
    printf("Hans           Druga instrukcja pisania\nKloss          Wciąż druga instrukcja pisania \n");
    printf("Hans Kloss     "); printf("Trzecia i czwarta instrukcja pisania \n");

    return 0;
}

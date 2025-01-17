/*
    r11z13.c: Praca z argumentami wiersza poleceń (potęgowanie)

    13. Napisz program do potęgowania działający w oparciu o wiersz poleceń.
    Pierwszym argumentem powinna być liczba typu "double" (podstawa potęgi),
    drugim - liczba calkowita (wykładnik).
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Podaj 2 (podstawe i wykladnik) parametry wiersza polecen! \n");
        return 1;
    }

    double base = atof(argv[1]);
    int exp = atoi(argv[2]);

    if(exp < 0) {
        base = (1.0 / base);
        exp *= -1;
    }

    double result = 1.0;

    for(int i = 0; i < exp; i++) {
        result *= base;
    }

    printf("%.2lf^%d = %.3lf \n", base, exp,result);

    return 0;
}

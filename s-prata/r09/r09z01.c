/*
    r09z01.c: Projekt funkcji min()

    1. Zaprojektuj funkcję 'min(x, y)', zwracającą mniejszą z dwóch wartości 
    typu 'double', i przetestuj ją za pomocą prostego programu.
*/

#include <stdio.h>
#include <assert.h>

double min(double, double);

int main(void) {

    assert(min(0.2, 0.4) == 0.2);
    assert(min(0.4, 0.2) == 0.2);
    assert(min(0.2, 0.2) == 0.2);
    assert(min(-0.2, 0.2) == -0.2);
    assert(min(0.2, -0.4) == -0.4);
    assert(min(-0.2, -0.4) == -0.4);

    return 0;
}

double min(double a, double b) {

    return a > b ? b : a;
}

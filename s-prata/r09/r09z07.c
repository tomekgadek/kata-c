/*
    r09z07.c: Potęgowanie przy pomocy funkcji rekurencynej

    7. Ponownie wykonaj ćwiczenie 6 – tym razem użyj funkcji rekurencyjnej.
*/

#include <stdio.h>
#include <assert.h>

double potega(double, int);

int main(void) {

    assert(potega(2.0, 3) == 8.0);
    assert(potega(2.0, -3) == 0.125);
    assert(potega(0.0, 5) == 0.0);
    assert(potega(2.0, 0) == 1.0);
    assert(potega(-2.0, 3) == -8.0);
    assert(potega(-2.0, 4) == 16.0);

    return 0;
}

double potega(double base, int exp) {

    if(exp == 0) {
        return 1.0;
    } else if(exp > 0) {
        return potega(base, exp-1) * base;
    } else {
        return potega(base, exp+1) * (1.0 / base);
    }
}

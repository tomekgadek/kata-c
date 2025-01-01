/*
    r09z06.c: Potęgowanie przy pomocy pętli programowej

    6. W Rozdziale 6 "Instrukcje sterujące C: Pętle" napisaliśmy funkcję 
    'potega()', która zwracała wynik podniesienia liczby typu 'double' do 
    potęgi naturalnej (patrz listing 6.18). Ulepsz tę funkcję tak, aby 
    poprawnie obsługiwała potęgi ujemne. Ponadto, wbuduj w funkcję 
    założenie, że 0 do dowolnej potęgi wynosi 0 oraz że podniesienie dowolnej 
    liczby do potęgi 0 daje wynik 1. Użyj pętli. Przetestuj funkcję w 
    programie.
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

double potega(double a, int b) {

    if(b == 0) {
        return 1.0;
    }

    double base = (b > 0 ? a : 1.0 / a);
    double exp = (b > 0 ? b : -b);
    double digit = 1.0;
        
    for(int e = 0; e < exp; e++) {

        digit *= base;
    }

    return digit;
}

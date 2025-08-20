/*
    r13z04.c: Zliczanie wywołań funkcji

    4. Napisz i przetestuj w pętli funkcję zwracającą liczbę razy, jaką 
    została wywołana.
*/

#include <stdio.h>

const int CALL_COUNT = 4;

int function(void);

int main(void) {

    int result = 0;
    for(int i = 0; i < CALL_COUNT; i++) {
        result = function();
    }
        
    printf("Funkcja zostala wywolana %d razy. \n", result);

    return 0;
}

int function(void) {

    static int counter = 0;

    return ++counter;
}

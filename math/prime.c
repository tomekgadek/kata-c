/*
    Liczby pierwsze.
*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

/**
 * Weryfikuje, czy podana liczba jest liczbą pierwszą.
 * 
 * @param digit liczba
 *
 * @return Czy podana liczba jest liczbą pierwszą, true = tak, false = nie
 */
bool is_prime(int digit);

int main(void) {

    assert(is_prime(2) == true);
    assert(is_prime(53) == true);
    assert(is_prime(-1) == false);
    assert(is_prime(0) == false);
    assert(is_prime(9739) == true);
    assert(is_prime(11262) == false);

    return 0;
}

bool is_prime(int digit) {

    bool prime = digit < 2 ? false : true;

    for(int i = 2; i < digit; i++) {
        
        if(digit % i == 0) {
            prime = false;
            break;
        }
    }

    return prime;
}
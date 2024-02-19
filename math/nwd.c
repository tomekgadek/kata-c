/*
    Największy wspólny dzielnik - algorytm Euklidesa.
*/

#include <stdio.h>
#include <assert.h>

/**
 * Odpowiada za wyznaczenie największego wspólnego dzielnika (GCD, NWD).
 * 
 * @param variable_a 1 liczba.
 * @param variable_b 2 liczba.
 *
 * @return Największy wspólny dzielnik z liczb variable_a oraz variable_b.
 */
int gcd(int variable_a, int variable_b);

int main(void) {

    assert(gcd(3, 9) == 3);
    assert(gcd(1, 2) == 1);
    assert(gcd(12, 6) == 6);
    assert(gcd(5, 13) == 1);
    assert(gcd(0, 0) == 0);

    return 0;
}

int gcd(int variable_a, int variable_b) {

    if(variable_b == 0) {
        return variable_a;
    }

    int variable_a_tmp = variable_a;

    variable_a = variable_b;
    variable_b = variable_a_tmp % variable_b;

    return gcd(variable_a, variable_b);
}

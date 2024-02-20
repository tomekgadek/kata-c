/*
    Najmniejsza wspólna wielokrotność.
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

/**
 * Odpowiada za wyznaczenie najmniejszej wspólnej wielokrotności (LCM, NWW).
 * 
 * @param variable_a 1 liczba.
 * @param variable_b 2 liczba.
 *
 * @return Najmniejsza wspólna wielokrotność dla liczb variable_a oraz variable_b.
 */
int lcm(int variable_a, int variable_b);

int main(void) {

    assert(lcm(42, 56) == 168);
    assert(lcm(192, 348) == 5568);

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

int lcm(int variable_a, int variable_b) {

    return (variable_a * variable_b) / gcd(variable_a, variable_b);
}

/*
    Odbicie lustrzane liczby całkowitej.

    Przykłady:

    123 -> 321
    -123 -> -321
    89 -> 98
*/

#include <stdio.h>
#include <assert.h>

/**
 * Odpowiada za "odbicie" liczby całkowitej.
 * 
 * @param input liczba wejściowa.
 *
 * @return liczba zapisana w odwrotnej kolejności.
 */
int reverse(int input);

int main(void) {

    assert(reverse(123) == 321);
    assert(reverse(-123) == -321);
    assert(reverse(1) == 1);
    assert(reverse(98) == 89);
    assert(reverse(120) == 21);
    assert(reverse(0) == 0);

    return 0;
}

int reverse(int input) {

    int positive_digit = input > 0 ? input : -input;
    int last_digit = 0;
    int result = 0;

    while(positive_digit > 0) {
        last_digit = positive_digit % 10;
        positive_digit = positive_digit / 10;

        result = result * 10 + last_digit;
    }

    return input > 0 ? result : -result;
}

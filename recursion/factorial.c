/*
	Program oblicza silnie.
*/

#include <stdio.h>
#include <assert.h>

/**
 * Oblicza silnie na podstawie podanej liczby.
 *
 * @param digit
 * 
 * @return
 */
long int factorial(long int digit);

int main(void) {

	long int digit;

	printf("Podaj liczbe: ");
	scanf("%ld", &digit);
	
	printf("Silnia z %ld wynosi %ld \n", digit, factorial(digit));

	return 0;
}

long int factorial(long int digit) {

    assert(digit >= 0);

    if(digit <= 1) {
        return 1;
    }

	return (digit > 1) ? digit * factorial(digit - 1) : digit;
}

/*
	Program, który wyznacza delte oraz miejsca zerowe funkcji kwadratowej.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "quadratic_function.h"

int main(void) {

    QuadraticFunction function1 = {1.0, -3.0, 2.0};
    ResultQuadraticFunctin *result1 = calculate_quadratic_function(&function1);
    assert(result1->delta == 1.000000);
    assert(result1->howManyZeros == TWO);
    assert(result1->x1 == 2.000000);
    assert(result1->x2 == 1.000000);
    free(result1);

    QuadraticFunction function2 = {1.0, -2.0, 1.0};
    ResultQuadraticFunctin *result2 = calculate_quadratic_function(&function2);
    assert(result2->delta == 0.000000);
    assert(result2->howManyZeros == ONE);
    assert(result2->x1 == 1.000000);
    free(result2);

    QuadraticFunction function3 = {1.0, 2.0, 3.0};
    ResultQuadraticFunctin *result3 = calculate_quadratic_function(&function3);
    assert(result3->delta == -8.000000);
    assert(result3->howManyZeros == ZERO);
    free(result3);

    printf("OK. \n");

    return 0;
}

/*
    Program, który wyznacza delte oraz miejsca zerowe funkcji kwadratowej.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "quadratic_function.h"

int main(void) {

    // given
    QuadraticFunction function1 = {1.0, -3.0, 2.0};

    // when
    ResultQuadraticFunctin *result1 = calculate_quadratic_function(&function1);

    // then
    assert(result1->delta == 1.000000);
    assert(result1->howManyZeros == TWO);
    assert(result1->x1 == 2.000000);
    assert(result1->x2 == 1.000000);

    // and
    free(result1);

    // given
    QuadraticFunction function2 = {1.0, -2.0, 1.0};

    // when
    ResultQuadraticFunctin *result2 = calculate_quadratic_function(&function2);

    // then
    assert(result2->delta == 0.000000);
    assert(result2->howManyZeros == ONE);
    assert(result2->x1 == 1.000000);

    // and
    free(result2);


    // given
    QuadraticFunction function3 = {1.0, 2.0, 3.0};

    // when
    ResultQuadraticFunctin *result3 = calculate_quadratic_function(&function3);

    // then
    assert(result3->delta == -8.000000);
    assert(result3->howManyZeros == ZERO);

    // and
    free(result3);

    printf("OK. \n");

    return 0;
}

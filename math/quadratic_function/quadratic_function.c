#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadratic_function.h"

ResultQuadraticFunctin *calculate_quadratic_function(QuadraticFunction *quadraticFunction) {

    if(quadraticFunction->a == 0) {
        printf("To nie jest funkcja kwadratowa! \n");
        return NULL;
    }

    ResultQuadraticFunctin *result = (ResultQuadraticFunctin *)malloc(sizeof(ResultQuadraticFunctin));
    if(result == NULL) {
        printf("Problem z alokacja pamieci! \n");
        return NULL;
    }

    double a = quadraticFunction->a;
    double b = quadraticFunction->b;
    double c = quadraticFunction->c;
        
    result->delta = pow(b, 2) - (4 * a * c);

    if(result->delta == 0) {
        double x = (-b) / (2 * a);
        result->howManyZeros = ONE;
		result->x1 = x;
        result->x2 = x;
    } else if(result->delta > 0) {
        result->howManyZeros = TWO;
        result->x1 = (-b + sqrt(result->delta))/(2 * a);
        result->x2 = (-b - sqrt(result->delta))/(2 * a);
    } else {
        result->howManyZeros = ZERO;
    }
        
    return result;
}

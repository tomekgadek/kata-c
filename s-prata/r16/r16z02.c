/*
    r15z02.c: Średnia harmoniczna

    2. Średnią harmoniczną dwóch liczb otrzymujemy przez obliczenie średniej 
    arytmetycznej ich odwrotności i odwrócenie wyniku. Za pomocą dyrektywy 
    #define zdefiniuj funkcję-makro wykonującą tę operację. Przetestuj ją w 
    prostym programie.
*/

#include <stdio.h>

#define HARMONIC_MEAN(x, y) ((2.0)/((1.0/(x))+(1.0/(y))))

int main(void) {

    printf("harmonic_mean(2,3) = %.2f \n", HARMONIC_MEAN(2, 3));
    printf("harmonic_mean(1,4) = %.2f \n", HARMONIC_MEAN(1, 4));
    printf("harmonic_mean(5,5) = %.2f \n", HARMONIC_MEAN(5, 5));
    printf("harmonic_mean(2,2) = %.2f \n", HARMONIC_MEAN(2, 2));

    return 0;
}

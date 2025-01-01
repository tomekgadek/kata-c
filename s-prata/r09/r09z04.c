/*
    r09z04.c: Średnia harmoniczna

    4. Średnią harmoniczną dwóch liczb uzyskujemy przez znalezienie odwrotności 
    danych liczb, wyciągnięciu z nich średniej arytmetycznej i obliczenie 
    odwrotności otrzymanego wyniku. Napisz funkcję, która pobiera dwa 
    argumenty typu 'double' i zwraca ich średnią harmoniczną.
*/

#include <stdio.h>
#include <stdlib.h>

double harmonic_mean(double, double);

int main(void) {

    printf("result = %.2lf \n", harmonic_mean(2.0, 8.0)); // 3.2

    return 0;
}

double harmonic_mean(double a, double b) {

    if (a == 0 || b == 0) {
        fprintf(stderr, "Error: a = 0 or b = 0 !!! \n");
        exit(1);
    }

    return (2.0 / (1.0 / a + 1.0 / b));
}

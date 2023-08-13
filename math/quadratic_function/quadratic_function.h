#ifndef QUADRATIC_FUNCTION_H
#define QUADRATIC_FUNCTION_H

/**
 * Typ wyliczeniowy reprezentujący liczbę miejsc zerowych funkcji kwadratowej.
 */
typedef enum {
    ZERO,
    ONE,
    TWO
} HowManyZeros;

/**
 * Struktura reprezentująca funkcję kwadratową.
 */
typedef struct {
    double a;
    double b;
    double c;
} QuadraticFunction;

/**
 * Struktura przechowująca wyniki obliczeń dla funkcji kwadratowej.
 */
typedef struct {
    double delta;
    double x1;
    double x2;
    HowManyZeros howManyZeros;

} ResultQuadraticFunctin;

/**
 * Oblicza wartości delty i miejsca zerowe funkcji kwadratowej.
 *
 * @param[in] quadraticFunction Wskaźnik do struktury QuadraticFunction zawierającej współczynniki funkcji kwadratowej.
 * @return Wskaźnik do struktury ResultQuadraticFunctin zawierającej wyniki obliczeń.
 */
ResultQuadraticFunctin *calculate_quadratic_function(QuadraticFunction *);

#endif
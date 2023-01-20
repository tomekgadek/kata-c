/*
    Srednia arytmetyczna.
*/

#include <stdio.h>
#include <assert.h>

/**
 * Liczy srednia arytmtyczna.
 *
 * @param *digits wskaznik do zbioru liczb.
 * @param size rozmiar zbioru liczb.
 *
 * @return suma wszystkich elementow ze zbioru / rozmiar zbioru.
 */
double average(double *digits, int size);

int main(void) {

    // given
    double digits_1[] = { 1.0, 2.0, 3.0 };
    double digits_2[] = { 1.0, 2.0 };
    double digits_3[] = { 2.0 };

    // then
    assert(average(digits_1, 3) == 2.0);
    assert(average(digits_2, 2) == 1.5);
    assert(average(digits_3, 1) == 2.0);

    return 0;
}

double average(double *digits, int size) {

    double sum = 0.0;

    for(int i = 0; i < size; i++) {
        sum = sum + *(digits + i);
    }

    return sum / (double) size;
}
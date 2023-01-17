/*
    Wyszukiwanie maksimum ze zbioru liczb calkowitych.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Odpowiada za wyszukiwanie najwiekszego elementu ze zbioru liczb calkowitych.
 *
 * @param digits[] zbior liczb calkowitych.
 * @param size rozmiar zbioru.
 *
 * @return najwieksza wartosc ze zbioru.
 */
int max(int digits[], int size);

int main(void) {

    // given
    int digits_schould_return_3[] = {1, 2, 3};
    int digits_schould_return_2[] = {2, 2, 2};
    int digits_schould_return_1[] = {1};

    // then
    assert(max(digits_schould_return_3, 3) == 3);
    assert(max(digits_schould_return_2, 2) == 2);
    assert(max(digits_schould_return_1, 1) == 1);

    printf("MAX(1, 2, 3) = %d \n", max(digits_schould_return_3, 3));

    return 0;
}

int max(int digits[], int size) {

    if(size < 1) {
        printf("Rozmiar musi byc wiekszy od 0! \n");
        exit(1);
    }

    int max = digits[0];
    for(int i = 1; i < size; i++) {

        if(digits[i] > max) {
            max = digits[i];
        }
    }

    return max;
}
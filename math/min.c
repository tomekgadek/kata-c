/*
    Wyszukiwanie minimum ze zbioru liczb calkowitych.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Odpowiada za wyszukiwanie najmniejszego elementu ze zbioru liczb calkowitych.
 *
 * @param digits[] zbior liczb calkowitych.
 * @param size rozmiar zbioru.
 *
 * @return najmniejsza wartosc ze zbioru.
 */
int min(int digits[], int size);

int main(void) {

    // given
    int digits_schould_return_3[] = {4, 7, 3};
    int digits_schould_return_2[] = {2, 2, 2};
    int digits_schould_return_1[] = {1};

    // then
    assert(min(digits_schould_return_3, 3) == 3);
    assert(min(digits_schould_return_2, 2) == 2);
    assert(min(digits_schould_return_1, 1) == 1);

    printf("MIN(4, 7, 3) = %d \n", min(digits_schould_return_3, 3));

    return 0;
}

int min(int digits[], int size) {

    if(size < 1) {
        printf("Rozmiar musi byc wiekszy od 0! \n");
        exit(1);
    }

    int min = digits[0];
    for(int i = 1; i < size; i++) {

        if(digits[i] < min) {
            min = digits[i];
        }
    }

    return min;
}
/*
    Sortowanie babelkowe.
*/

#include <stdio.h>
#include <assert.h>

/**
 * Realizuje algorytm sortowania babelkowego na liczba calkowitych
 *
 * @param *digits wskaznik do tablicy liczb calkowitych.
 * @param size rozmiar tablicy liczb calkowitych.
 *
 * @return adres posortowanej tablicy.
 */
int *bubble_sort(int *digits, int size);

int main(void) {

    const int size = 7;
    int digits[] = {5, 1, 2, 4, 3, 6, 7};

    int *result_digits = bubble_sort(digits, size);

    for(int i = 0; i < size; i++) {
        assert(result_digits[i] == (i + 1));

        printf("(%d)", result_digits[i]);
    }

    printf("\n");

    return 0;
}

int *bubble_sort(int *digits, int size) {

    for(int i = 0; i < size; i++) {

        for(int j = 0; j < size-1; j++) {

            if(digits[j] >= digits[j+1]) {
                digits[j] = digits[j] ^ digits[j+1]; // XOR
                digits[j+1] = digits[j] ^ digits[j+1];
                digits[j] = digits[j] ^ digits[j+1];
            }
        }

        size -= 1;  // Najwiekszy element znajduje sie na koncu, wiec nie musimy brac go pod uwage.
    }

    return digits;
}
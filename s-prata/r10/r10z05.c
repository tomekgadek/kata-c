/*
    r10z05.c: Różnica między największym i najmniejszym elementem tablicy

    5. Napisz funkcję, która zwraca różnicę między największym i najmniejszym 
    elementem w tablicy. Przetestuj ją w prostym programie.
*/

#include <stdio.h>
#include <assert.h>

int get_diff_max_min(int digits[], int size);

int main(void) {

    int digits1[] = { 1 };
    int digits2[] = { 2, 1, 3 };
    int digits3[] = { 4, 4, 4 };
    int digits4[] = { 4, 4, 0, 1 };

    assert(get_diff_max_min(digits1, sizeof(digits1) / sizeof(int)) == 0);
    assert(get_diff_max_min(digits2, sizeof(digits2) / sizeof(int)) == 2);
    assert(get_diff_max_min(digits3, sizeof(digits3) / sizeof(int)) == 0);
    assert(get_diff_max_min(digits4, sizeof(digits4) / sizeof(int)) == 4);

    return 0;
}

int get_diff_max_min(int digits[], int size) {

    int max = digits[0];
    int min = digits[0];

    for(int i = 1; i < size; i++) {

        if(max < digits[i]) {
            max = digits[i];
        }

        if(min > digits[i]) {
            min = digits[i];
        }
    }

    return max - min;
}

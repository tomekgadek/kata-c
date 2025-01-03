/*
    r10z04.c: Pobierz indeks największego elementu z tablicy

    4. Napisz funkcję, która zwraca indeks największej wartości przechowywanej 
    w tablicy. Przetestuj ją w prostym programie.
*/

#include <stdio.h>
#include <assert.h>

int get_index_of_max(int digits[], int size);

int main(void) {

    int digits1[] = { 1 };
    int digits2[] = { 2, 1, 3 };
    int digits3[] = { 4, 4, 4 };
    int digits4[] = { 4, 4, 0, 1 };

    assert(get_index_of_max(digits1, sizeof(digits1) / sizeof(int)) == 0);
    assert(get_index_of_max(digits2, sizeof(digits2) / sizeof(int)) == 2);
    assert(get_index_of_max(digits3, sizeof(digits3) / sizeof(int)) == 0);
    assert(get_index_of_max(digits4, sizeof(digits4) / sizeof(int)) == 0);

    return 0;
}

int get_index_of_max(int digits[], int size) {

    int max = digits[0];
    int max_idx = 0;

    for(int i = 1; i < size; i++) {

        if(max < digits[i]) {
            max = digits[i];
            max_idx = i;
        }
    }

    return max_idx;
}

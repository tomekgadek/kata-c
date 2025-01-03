/*
    r10z03.c: Pobierz największy element z tablicy

    3. Napisz funkcję, która zwraca największą wartość przechowywaną w tablicy. 
    Przetestuj ją w prostym programie.
*/

#include <stdio.h>
#include <assert.h>

int get_max(int digits[], int size);

int main(void) {

    int digits1[] = { 1 };
    int digits2[] = { 2, 1, 3 };
    int digits3[] = { 4, 4, 4 };
    int digits4[] = { 4, 4, 0, 1 };

    assert(get_max(digits1, sizeof(digits1) / sizeof(int)) == 1);
    assert(get_max(digits2, sizeof(digits2) / sizeof(int)) == 3);
    assert(get_max(digits3, sizeof(digits3) / sizeof(int)) == 4);
    assert(get_max(digits4, sizeof(digits4) / sizeof(int)) == 4);

    return 0;
}

int get_max(int digits[], int size) {

    int max = digits[0];

    for(int i = 1; i < size; i++) {

        if(max < digits[i]) {
            max = digits[i];
        }
    }

    return max;
}

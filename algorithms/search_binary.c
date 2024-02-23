/*
    Wyszukiwanie binarne.
*/

#include <stdio.h>
#include <assert.h>

/**
 * Wyszukuje index pod jakim kryje się konkretna liczba.
 *
 * @param digits tablica liczb całkowitych.
 * @param size rozmiar tablicy liczb całkowitych.
 * @param search_value wartość wyszukiwanej liczby.
 *
 * @return index odnalezionej liczby, w przeciwnym wypadku -1
 */
int find_idx(int digits[], int size, int search_value);

int main(void) {
    // given
    int digits[] = {2, 4, 5, 6, 7, 9, 10, 23, 89};

    const int size = 9;
    const int search_value = 10;
    const int expected_value = 6;

    // when
    const int result_idx = find_idx(digits, size, search_value);
    
    // then
    assert(result_idx == expected_value);

    return 0;
}

int find_idx(int digits[], int size, int search_value) {
    const int DIGIT_NOT_FOUND = -1;

    int left = 0;
    int right = size - 1;
    int result_idx;

    while(left <= right) {
        result_idx = (left + right) / 2;

        if(digits[result_idx] < search_value) {
            left = result_idx + 1;
        } else if(digits[result_idx] > search_value) {
            right = result_idx - 1;
        } else {
            return result_idx;
        }
    }

    return DIGIT_NOT_FOUND;
}

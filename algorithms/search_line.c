/*
    Wyszukiwanie liniowe.
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
    int digits[] = {5, 1, 2, 4, 3, 6, 7};

    const int size = 7;
    const int search_value = 4;
    const int expected_value = 3;

    // when
    const int result_idx = find_idx(digits, size, search_value);
    
    // then
    assert(result_idx == expected_value);
    
    return 0;
}

int find_idx(int digits[], int size, int search_value) {
    const int DIGIT_NOT_FOUND = -1;

    for(int i = 0; i < size; i++) {
        if(search_value == digits[i]) {
            return i;
        }
    }

    return DIGIT_NOT_FOUND;
}

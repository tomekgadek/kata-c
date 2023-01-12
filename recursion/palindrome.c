/*
    Program weryfikuje, czy podany ciag tektowy to tzw. palindrom.
*/

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/**
 * Weryfikuje, czy podany ciag tekstowy to palindrom.
 * 
 * @param idx_left idx pierwszego znaku w ciagu tekstowym.
 * @param idx_right idx ostatniego znaku w ciagu tekstowym.
 * @param text ciag tekstowy.
 *
 * @return true - ciag tekstowy to palindrom, false - ciag tekstowy nie jest palindromem.
 */
bool is_palindrome(int idx_left, int idx_right, char *text);

int main(void) {

    assert(is_palindrome(0, 2, "ada") == true);
    assert(is_palindrome(0, 6, "1234321") == true);
    assert(is_palindrome(0, 9, "JavaScript") == false);
    assert(is_palindrome(0, 3, "abba") == true);
    assert(is_palindrome(0, 0, "b") == true);
    assert(is_palindrome(0, 3, "abab") == false);

    printf("Done. \n");

    return 0;
}

bool is_palindrome(int idx_left, int idx_right, char *text) {

    if(text[idx_left] != text[idx_right]) {
        return false;
    }

    if(idx_left >= idx_right) {
        return true;
    }

    return is_palindrome(++idx_left, --idx_right, text);
}
/*
    Program porownuje ciagi tekstowe.
*/

#include <stdio.h>
#include <assert.h>

/**
 * Porownuje dlugosci ciagow tekstowych.
 * 
 * @param text_first adres pierwszego ciągu tekstowego.
 * @param text_second adres drugiego ciagu tekstowego.
 *
 * @return 1 - text_first > text_second, 2 - text_first < text_second, 0 - text_first = text_second.
 */
int compare(char *text_first, char *text_second);

int main(void) {

    assert(compare("Java", "C++") == 1);
    assert(compare("C++", "Java") == 2);
    assert(compare("Python", "Python") == 0);
    assert(compare("PHP", "php") == 0);
    assert(compare("_+_", ";-)") == 0);
    assert(compare("", "") == 0);

    printf("Done. \n");

    return 0;
}

int compare(char *text_first, char *text_second) {

    while(*text_first && *text_second) {
        text_first++;
        text_second++;
    }

    if(*text_first) {
        return 1;
    }

    if(*text_second) {
        return 2;
    }

    return 0;
}

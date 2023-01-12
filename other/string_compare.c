/*
    Program porownuje ciagi tekstowe.
*/

#include <stdio.h>
#include <assert.h>

/**
 * Porownuje dlugosci ciagow tekstowych.
 * 
 * @param textFirst adres pierwszego ciągu tekstowego.
 * @param textSecond adres drugiego ciagu tekstowego.
 *
 * @return 1 - textFirst > textSecond, 2 - textFirst < textSecond, 0 - textFirst = textSecond.
 */
int compare(char *textFirst, char *textSecond);

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

int compare(char *textFirst, char *textSecond) {

    while(*textFirst && *textSecond) {
        textFirst++;
        textSecond++;
    }

    if(*textFirst) {
        return 1;
    }

    if(*textSecond) {
        return 2;
    }

    return 0;
}

/* 16L07.c: Przekazywanie tablicy wskaznikow do funkcji */

#include <stdio.h>

/* deklaracje funkcji */
void strPrint1(char **str1, int size);
void strPrint2(char *str2);

/* poczatek funkcji main() */
int main(void) {

    char *str[4] = {
        "* Kto jest twoja konkurencja?",
        "* Kto jest twoim potencjalnym klientem?",
        "* Czym wyrozni sie twoj program ponad konkurencje?",
        "* Jak duzy jest potencjalny rynek?\n"
    };

    int i, size=4;
    puts("Zanim opracujesz program, zadaj sobie nastepujace pytania:");
    strPrint1(str, size);
    for(i = 0; i < 4; i++)
        strPrint2(str[i]);

    return 0;
}

/* definicja funkcji */
void strPrint1(char **str1, int size) {
    int i;
    for(i = 0; i < size; i++)
        printf("%s\n", str1[i]);
}

/* definicja funkcji */
void strPrint2(char *str2) {

    printf("%s\n",str2);
}

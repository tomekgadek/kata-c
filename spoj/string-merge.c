/*
    string-merge.c: PP0504B - StringMerge

    Zadanie: https://pl.spoj.com/problems/PP0504B/

    Kompilacja oraz uruchomienie programu: gcc string-merge.c && ./a.out < ./tests/string-merge-tests.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TXT_SIZE 1001

char *string_merge(char *, char *);

int main(void) {

    int number_of_tests = 0;
    scanf("%d", &number_of_tests);

    char txt_first[TXT_SIZE], txt_second[TXT_SIZE];

    for(int i = 0; i < number_of_tests; i++) {
        scanf("%s %s", txt_first, txt_second);

        char *merged = string_merge(txt_first, txt_second);
        printf("%s \n", merged);

        free(merged);
    }

    return 0;
}

char *string_merge(char *txt_first, char *txt_second) {

    int txt_first_size = strlen(txt_first);
    int txt_second_size = strlen(txt_second);

    int size = txt_first_size <= txt_second_size ? txt_first_size : txt_second_size;

    char *merged = (char *)malloc(size * 2 + 1);

    if(merged == NULL) {
        exit(1);
    }

    for(int i = 0; *txt_first && *txt_second; i += 2) {
        merged[i] = *txt_first++;
        merged[i+1] = *txt_second++;
    }

    merged[size * 2] = '\0';

    return &merged[0];
}

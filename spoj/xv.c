/*
    xv.c: WZP09_2F - XV

    Zadanie: https://pl.spoj.com/problems/WZP09_2F/

    Kompilacja oraz uruchomienie programu: gcc xv.c && ./a.out < ./tests/xv-tests.txt
*/
#include <stdio.h>

#define LINE   1000
#define TRUE   1
#define FALSE  0
#define MSG_Y  "TAK"
#define MSG_N  "NIE"

int char_to_int(char);
int str_size(const char *);
int divide_3(const char *);
int divide_5(const char *);

int main(void) {

    char text[LINE+1];

    int text_size = 0;
    while(fgets(text, sizeof(text), stdin) != NULL && text[0] != '0') {
        text_size = str_size(text);
        if (text_size > 0 && text[text_size-1] == '\n') {
            text[text_size-1] = '\0';
        }

        divide_3(text) == TRUE && divide_5(text) == TRUE? puts(MSG_Y) : puts(MSG_N);
    }

    putchar('\n');

    return 0;
}

int char_to_int(char sign) {
    return (sign - '0');
}

int str_size(const char *wsk) {
    int counter = 0;

    while(*wsk++) {
        counter++;
    }

    return counter;
}

int divide_3(const char *wsk) {
    int sum = 0;

    while(*wsk) {
        sum += char_to_int(*wsk++);
    }

    return sum % 3 == 0;
}

int divide_5(const char *wsk) {
    int size = str_size(wsk);

    if(wsk[size-1] == '0' || wsk[size-1] == '5') {
        return 1;
    }

    return 0;
}

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

int charToInt(char);
int strlen(const char *);
int divide3(const char *);
int divide5(const char *);

int main(void) {

    char text[LINE+1];

    while(gets(text) != NULL && text[0] != '0') {
        divide3(text) == TRUE && divide5(text) == TRUE? puts(MSG_Y) : puts(MSG_N);
    }

    putchar('\n');

    return 0;
}

int charToInt(char sign) {
    return (sign - '0');
}

int strlen(const char *wsk) {
    int counter = 0;

    while(*wsk++) {
        counter++;
    }

    return counter;
}

int divide3(const char *wsk) {
    int sum = 0;

    while(*wsk) {
        sum += charToInt(*wsk++);
    }

    return sum % 3 == 0;
}

int divide5(const char *wsk) {
    int size = strlen(wsk);

    if(wsk[size-1] == '0' || wsk[size-1] == '5') {
        return 1;
    }

    return 0;
}

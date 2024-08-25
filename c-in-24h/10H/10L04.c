/* 10L04.c: Zastosowanie instrukcji switch */

#include <stdio.h>

int main(void) {

    int day;
    
    printf("Wpisz 1 cyfre - numer dnia \n");
    printf("(z zakresu od 1 do 3):\n");

    day = getchar();
    switch(day) {
        case'1':
            printf("Dzien 1\n");
        case'2':
            printf("Dzien 2\n");
        case'3':
            printf("Dzien 3\n");      
        default:
            ;
    }

    return 0;
}

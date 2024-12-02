/*
    r05z01.c: Przelicz minuty na godziny i minuty

    1. Użyj pętli while do przeliczenia czasu w minutach na godziny i minuty. 
    Utwórz stałą symboliczną dla liczby 60 przy pomocy #define lub const i 
    pamiętaj o zapewnieniu sposobu zakończenia pętli.
*/

#include <stdio.h>

const int MINUTES_IN_HOUR = 60;

int main(void) {

    int hours = 0, minutes = 0, insert_minutes = 0;

    printf("Podaj minuty: ");
    scanf("%d", &insert_minutes);

    minutes = insert_minutes;

    while(minutes >= MINUTES_IN_HOUR) {
        hours += 1;
        minutes -= MINUTES_IN_HOUR;
    }

    printf("%dmin = %dh i %dmin \n", insert_minutes, hours, minutes);

    return 0;
}

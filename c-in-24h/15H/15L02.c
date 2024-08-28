/* 15L02.c: Funkcja bezargumentowa, nie zwraca wartosci */

#include <stdio.h>
#include <time.h>

void podajDateICzas(void);

int main(void) {

    printf("Przed wywolaniem.\n");
    podajDateICzas();
    printf("Po wywolaniu.\n");

    return 0;
}

void podajDateICzas(void) {

    time_t teraz;

    printf("We wnetrzu funkcji podajDateICzas().\n");
    time(&teraz);
    printf("Aktualna data i czas: %s", asctime(localtime(&teraz)));
}

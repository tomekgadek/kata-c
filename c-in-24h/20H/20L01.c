/* 20L01.c: Odwolywanie sie do unii */

#include <stdio.h>
#include <string.h>

int main(void) {

    union menu {

        char nazwa[23];
        double cena;
    } danie;

    printf("Zawartosc unii po kolei: \n");

    /* dostep do elementu unii nazwa */
    strcpy(danie.nazwa, "Kura slodko-kwasna");
    printf("Nazwa dania: %s \n", danie.nazwa);
    /* dostep do elementu unii cena */
    danie.cena = 9.95;
    printf("Cena dania: %5.2f \n", danie.cena);
    printf("Zawartosc unii koncowa: %s \n", danie.nazwa); /* nakladanie */

    return 0;
}

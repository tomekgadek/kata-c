/*
    r13z01.c: pobierz.c
*/

#include <stdio.h>

#define NIENUM 0
#define TAKNUM 1

int pobierz(int tablica[], int granica) {

    int num, stan;
    int index = 0; /* indeks tablicy */

    printf("Ten program konczy odczytywanie liczb po pobraniu %d ", granica);
    printf("wartosci\nlub w przypadku wpisania #. Pierwsza wartosc: ");
    stan = scanf("%d", &num);
    while (index < granica) {
        if (stan == TAKNUM) {
            tablica[index++] = num;
            printf("%d przyjete. ", num);
            if (index < granica) { /* jesli jest miejsce, */
                /* pobierz kolejna wartosc */
                printf("Nastepna wartosc: ");
                stan = scanf("%d", &num);
            }
        } else if (stan == NIENUM) {
            //scanf("%*s"); /* pozbywa sie zlych danych wejsciowych */
            char czy_koniec = '?';
            scanf(" %c", &czy_koniec);

            if(czy_koniec == '#') {
                break; /* opuszcza petle, jesli wpisano # */
            }

            printf("To nie byla liczba calkowita! Wpisz liczbe calkowita, aby\n");
            printf("kontynuowac lub cos, co nie jest liczba, aby zakonczyc: ");

            if ((stan = scanf("%d", &num)) == NIENUM) {
                break; /* opuszcza petle, jesli dane sa nienumeryczne */
            }
        } else {
            printf("Ups! Program nie powinien nigdy dotrzec w to miejsce!\n");
            break;
        }
    }

    if (index == granica) { /* zawiadamia o przepelnieniu tablicy */
        printf("Wszystkie %d elementow tablicy zostalo wypelnione.\n", index);
    }

    return(index);
}

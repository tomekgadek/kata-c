/*
    r13z01.c: Zakończenie programu po wpisaniu znaku #

    1. Niektórzy użytkownicy mogą być zakłopotani prośbą programu o wpisanie 
    znaku EOF. Zmień funkcję pobierz() tak, aby mogła ona zostać zakończona 
    przez wpisanie znaku #.
*/

/*
    r13z01.c: sort_int.c -- porzadkuje liczby calkowite
*/

#include <stdio.h>

#define MAX_ROZM 100 /* ograniczenie liczby wartosci */

extern int pobierz(int tab[], int n);
extern void sort(int tab[], int n);
extern void wyswietl(const int tab[], int n);

int main(void) {

    int liczby[MAX_ROZM]; /* tablica na dane wejsciowe */
    int rozmiar; /* liczba pozycji wejsciowych */

    rozmiar = pobierz(liczby, MAX_ROZM); /* umieszcza dane w tablicy */
    printf("\nPierwotne dane (%d wartosci):\n", rozmiar);
    wyswietl(liczby, rozmiar); /* wyswietla tablice wyjsciowa */
    sort(liczby, rozmiar); /* porzadkuje tablice */
    puts("Posortowane dane: ");
    wyswietl(liczby, rozmiar); /* wyswietla uporzadkowana tablice */

    return 0;
}

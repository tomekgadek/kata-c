/* 03L02.c: Obliczanie sumy i drukowanie wyniku na ekranie */

#include <stdio.h>

/* Ta funkcja dodaje dwie liczby calkowite i zwraca wynik dodawania */
int dodaj(int x, int y) {
    int wynik; /* deklaracja, zmienna "wlasna" funkcji */

    wynik = x+y;

    return wynik;
} 

int main(void) {

    int suma; /* deklaracja zmiennej */

    suma = dodaj(5, 12);
    printf("Wynik dodawania 5 oraz 12 wynosi %d \n", suma);

    return 0;
}
   
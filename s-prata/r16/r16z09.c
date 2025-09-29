/*
    r16z09.c: Porządkowanie tablicy struktur

    9. Zmodyfikuj listing 16.13 tak, aby porządkował tablicę typu struct osoba 
    (zdefiniowaną w tekście po listingu) zamiast tablicy typu double. Użyj 
    mniejszej liczby elementów i zainicjalizuj je własnoręcznie.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 5
#define TXT 30

struct osoba {
    char imie[TXT];
    char nazwisko[TXT];
    int wiek;
};

void pokaz_tab(const struct osoba tab[], int n);
int porownaj(const void * w1, const void * w2);

int main(void) {
    struct osoba osoby[NUM] = {
        {"Jan", "Kowalski", 34},
        {"Anna", "Nowak", 28},
        {"Piotr", "Zielinski", 45},
        {"Maria", "Lewandowska", 31},
        {"Tomasz", "Wozniak", 40}
    };

    puts("Lista pierwotna:");
    pokaz_tab(osoby, NUM);
    qsort(osoby, NUM, sizeof(struct osoba), porownaj);
    puts("\nLista uporzadkowana (wg nazwiska):");
    pokaz_tab(osoby, NUM);
    return 0;
}

void pokaz_tab(const struct osoba tab[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%-10s %-15s %3d\n", tab[i].imie, tab[i].nazwisko, tab[i].wiek);
    }
}

/* porzadkuje wg wieku w kolejnosci rosnacej */
int porownaj(const void * w1, const void * w2) {
    const struct osoba * a1 = (const struct osoba *)w1;
    const struct osoba * a2 = (const struct osoba *)w2;
    return a1->wiek - a2->wiek;
}

/*
    r14z03.c: Wyświetlanie książek w porządku alfabetycznym

    3. Zmodyfikuj program z listingu 14.2 tak, aby wyświetlał on opisy książek 
    w porządku alfabetycznym (wg tytułu) oraz całkowitą wartość książek.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTYT 40
#define MAXAUT 40
#define MAXKS  100 // maksymalna ilosc ksiazek

// definuje szblon ksiazka
struct ksiazka {
    char tytul[MAXTYT];
    char autor[MAXAUT];
    float wartosc;
};

void sortuj(struct ksiazka *, int);
float wylicz_calkowita_wartosc(struct ksiazka *, int);

int main(void) {

    struct ksiazka bibl[MAXKS]; // tablica struktur typu ksiazka

    printf("Podaj tytul ksiazki. ");
    printf("Aby zakonczyc nacisnij [enter] na poczatku wiersza. \n");

    int licznik = 0;
    while(licznik<MAXKS && fgets(bibl[licznik].tytul, MAXTYT, stdin) != NULL && bibl[licznik].tytul[1] != '\0') {

        bibl[licznik].tytul[strcspn(bibl[licznik].tytul, "\n")] = '\0';

        printf("Teraz podaj autora. \n");
        fgets(bibl[licznik].autor, MAXTYT, stdin);
        bibl[licznik].autor[strcspn(bibl[licznik].autor, "\n")] = '\0';

        printf("Teraz podaj wartosc. \n");
        scanf("%f", &bibl[licznik++].wartosc);

        while(getchar() != '\n')
            continue; // czysci bufor wejsciowy

        if(licznik < MAXKS)
            printf("Podaj kolejny tytul. \n");
    }

    int liczba_ksiazek = licznik;

    sortuj(&bibl[0], liczba_ksiazek);
    float calkowity_koszt = wylicz_calkowita_wartosc(&bibl[0], liczba_ksiazek);

    printf("--- \n");
    printf("Posortowane ksiazki wg tutulu: \n");
    for(int i = 0; i < liczba_ksiazek; i++) {
        printf("%s, autor %s, cena: %.2f zl. \n", 
            bibl[i].tytul, bibl[i].autor, bibl[i].wartosc);
    }

    printf("--- \n");
    printf("Calkowity koszt ksiazek wynosi %.2f zl. \n", calkowity_koszt);

    return 0;
}

void sortuj(struct ksiazka *w_ks, int rozmiar) {

    for(int i = 0; i < (rozmiar-1); i++) {

        int max_idx = i;
        for(int j = (i+1); j < rozmiar; j++) {

            if(strcmp(w_ks[i].tytul, w_ks[j].tytul) < 0) {
                max_idx = j;
            }

            struct ksiazka kopia = w_ks[max_idx];
            w_ks[max_idx] = w_ks[j];
            w_ks[j] = kopia;
        }
    }
}

float wylicz_calkowita_wartosc(struct ksiazka *w_ks, int rozmiar) {

    float suma_wart = 0.0;

    for(int i = 0; i < rozmiar; i++) {
        suma_wart += w_ks[i].wartosc;
    }

    return suma_wart;
}

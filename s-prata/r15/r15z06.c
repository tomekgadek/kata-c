/*
    r15z06.c: Program wykorzystujący operacje bitowe zamiast pól bitowych

    6. Napisz program realizujący te same zadania, co listing 15.3, ale 
    wykorzystujący wartość `unisgned int` i operatory bitowe zamiast
    struktury i pól bitowych.
*/

#include <stdio.h>
#include <string.h>

/* przezroczystość, widoczność */
#define TAK 1
#define NIE 0

/* style linii */
#define CIAGLA 0
#define KROPKI 1
#define KRESKI 2

/* barwy podstawowe */
#define NIEB 4
#define ZIEL 2
#define CZER 1

/* barwy mieszane */
#define CZARNY 0
#define ZOLTY (CZER | ZIEL) // 3
#define FIOLET (CZER | NIEB) // 5
#define ZIELNIEB (ZIEL | NIEB) // 6
#define BIALY (CZER | ZIEL | NIEB) // 7

const char *kolory[8] = {
    "czarny", "czerwony", "zielony", "zolty",
    "niebieski", "fioletowy", "zielononiebieski", "bialy"
};

/*
    wagi bitow od 0 do 9:

    0 = 2^0 = 1 = przezroczystość
    1 = 2^1 = 2 = kolor wypełnienia (bit 1)
    2 = 2^2 = 4 = kolor wypełnienia (bit 2)
    3 = 2^3 = 8 = kolor wypełnienia (bit 3)
    4 = 2^4 = 16 = widoczność ramki
    5 = 2^5 = 32 = kolor ramki (bit 1)
    6 = 2^6 = 64 = kolor ramki (bit 2)
    7 = 2^7 = 128 = kolor ramki (bit 3)
    8 = 2^8 = 256 = styl ramki (bit 1)
    9 = 2^9 = 512 = styl ramki (bit 2)
*/

unsigned int w_okna = 0; // wszystkie bity wyzerowane

void ustaw_parametry_okna(unsigned int *okno, const char *polecenie, int wartosc);
unsigned int pobierz_parametry_okna(const unsigned int okno, const char *polecenie);

int main(void) {

    /* tworzy i inicjalizuje okno */
    ustaw_parametry_okna(&w_okna, "przezrocz", TAK);
    ustaw_parametry_okna(&w_okna, "kolor_wyp", ZOLTY);
    ustaw_parametry_okna(&w_okna, "wid_ramki", TAK);
    ustaw_parametry_okna(&w_okna, "kolor_ramki", ZIEL);
    ustaw_parametry_okna(&w_okna, "styl_ramki", KRESKI);

    printf("Okno jest %s. \n",
        pobierz_parametry_okna(w_okna, "przezrocz") == TAK ? "przezroczyste" : "nieprzezroczyste");
    printf("Ramka jest narysowana linia ");

    switch (pobierz_parametry_okna(w_okna, "styl_ramki")) {
        case CIAGLA: printf("ciagla.\n"); break;
        case KROPKI: printf("wykropkowana.\n"); break;
        case KRESKI: printf("kreskowana.\n"); break;
        default:     printf("nieznanego typu.\n");
    }

    printf("Kolorem wypelnienia jest %s. \n", kolory[pobierz_parametry_okna(w_okna, "kolor_wyp")]);
    printf("Kolorem ramki jest %s. \n", kolory[pobierz_parametry_okna(w_okna, "kolor_ramki")]);

    ustaw_parametry_okna(&w_okna, "przezrocz", NIE);
    ustaw_parametry_okna(&w_okna, "kolor_wyp", BIALY);
    ustaw_parametry_okna(&w_okna, "kolor_ramki", FIOLET);
    ustaw_parametry_okna(&w_okna, "styl_ramki", CIAGLA);

    printf("\nPo dokonaniu zmian okno jest %s. \n",
           pobierz_parametry_okna(w_okna, "przezrocz") == TAK ? "przezroczyste" : "nieprzezroczyste");
    printf("Ramka jest narysowana linia ");

    switch (pobierz_parametry_okna(w_okna, "styl_ramki")) {
        case CIAGLA: printf("ciagla. \n"); break;
        case KROPKI: printf("wykropkowana. \n"); break;
        case KRESKI: printf("kreskowana. \n"); break;
        default:     printf("nieznanego typu. \n");
    }

    printf("Kolorem wypelnienia jest %s.\n", kolory[pobierz_parametry_okna(w_okna, "kolor_wyp")]);
    printf("Kolorem ramki jest %s.\n", kolory[pobierz_parametry_okna(w_okna, "kolor_ramki")]);

    return 0;
}

void ustaw_parametry_okna(unsigned int *okno, const char *polecenie, int wartosc) {

    if (strcmp(polecenie, "przezrocz") == 0) {
        if (wartosc == TAK) {
            *okno |= 1; // ustaw bit 0 (maska = 0b0000000001)
        } else {
            *okno &= ~1; // wyzeruj bit 0
        }

    } else if (strcmp(polecenie, "kolor_wyp") == 0) {
        *okno &= ~14; // wyzeruj bity 1, 2, 3 (maska = 0b1110)
        *okno |= (wartosc << 1); // ustaw bity 1–3

    } else if (strcmp(polecenie, "wid_ramki") == 0) {
        if (wartosc == TAK) {
            *okno |= 16; // ustaw bit 4 (maska = 0b10000)
        } else {
            *okno &= ~16; // wyzeruj bit 4
        }

    } else if (strcmp(polecenie, "kolor_ramki") == 0) {
        *okno &= ~224; // wyzeruj bity 5, 6, 7 (maska = 0b11100000)
        *okno |= (wartosc << 5); // ustaw bity 5–7

    } else if (strcmp(polecenie, "styl_ramki") == 0) {
        *okno &= ~768; // wyzeruj bity 8, 9 (maska = 0b1100000000)
        *okno |= (wartosc << 8); // ustaw bity 8–9

    } else {
        printf("Nieznane polecenie: %s. \n", polecenie);
    }
}

unsigned int pobierz_parametry_okna(const unsigned int okno, const char *polecenie) {

    if (strcmp(polecenie, "przezrocz") == 0) {
        return okno & 1; // zwróć bit 0

    } else if (strcmp(polecenie, "kolor_wyp") == 0) {
        return (okno >> 1) & 7;   // zwróć bity 1–3

    } else if (strcmp(polecenie, "wid_ramki") == 0) {
        return (okno >> 4) & 1;   // zwróć bit 4

    } else if (strcmp(polecenie, "kolor_ramki") == 0) {
        return (okno >> 5) & 7;   // zwróć bity 5–7

    } else if (strcmp(polecenie, "styl_ramki") == 0) {
        return (okno >> 8) & 3;   // zwróć bity 8–9

    } else {
        printf("Nieznane polecenie: %s. \n", polecenie);
        return -1;
    }
}

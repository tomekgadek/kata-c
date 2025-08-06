/*
    r12z02.c: Zbiorowy odczyt plików z linii poleceń oraz dopisywanie ich 
    zawartości do pliku docelowego

    3. Zmodyfikuj program z listingu 12.6 tak, aby wykorzystywał on interfejs 
    oparty na wierszu poleceń, a nie interfejs interaktywny. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZMIAR_BUF 1024
#define DLAN 50

char temp[ROZMIAR_BUF];
void dopisz(FILE *zrodlo, FILE *cel);

int main(int argc, char *argv[]) {

    FILE *pd, *pz;
    int pliki = 0;
    char plik_doc[DLAN];
    char plik_zro[DLAN];

    if (argc < 3) {
        fprintf(stderr, "Sposob uzycia: %s plik_docelowy plik_zrodlowy1 [plik_zrodlowy2 ...]\n", argv[0]);
        exit(1);
    }

    strncpy(plik_doc, argv[1], DLAN - 1);
    plik_doc[DLAN - 1] = '\0';

    if ((pd = fopen(plik_doc, "a")) == NULL) {
        fprintf(stderr, "Blad otwarcia %s\n", plik_doc);
        exit(2);
    }

    if (setvbuf(pd, NULL, _IOFBF, ROZMIAR_BUF) != 0) {
        fputs("Nie mozna utworzyc bufora wyjsciowego \n", stderr);
        exit(3);
    }

    for (int i = 2; i < argc; i++) {
        strncpy(plik_zro, argv[i], DLAN - 1);
        plik_zro[DLAN - 1] = '\0';

        if (strcmp(plik_zro, plik_doc) == 0)
            fputs("Nie mozna dopisac pliku do siebie \n", stderr);
        else if ((pz = fopen(plik_zro, "r")) == NULL)
            fprintf(stderr, "Blad otwarcia pliku %s \n", plik_zro);
        else {
            if (setvbuf(pz, NULL, _IOFBF, ROZMIAR_BUF) != 0) {
                fputs("Nie mozna utworzyc bufora wejsciowego \n", stderr);
                fclose(pz);
                continue;
            }

            dopisz(pz, pd);
            if (ferror(pz) != 0)
                fprintf(stderr, "Blad odczytu pliku %s \n", plik_zro);
            if (ferror(pd) != 0)
                fprintf(stderr, "Blad zapisu pliku %s \n", plik_doc);

            fclose(pz);

            pliki++;

            printf("Plik %s dopisany. \n", plik_zro);
        }
    }

    printf("Koniec. Dopisano %d plikow. \n", pliki);
    fclose(pd);

    return 0;
}

void dopisz(FILE *zrodlo, FILE *cel) {

    size_t bajty;
    extern char temp[]; /* korzysta z tablicy zewnetrznej temp */

    while ((bajty = fread(temp, sizeof(char), ROZMIAR_BUF, zrodlo)) > 0)
        fwrite(temp, sizeof(char), bajty, cel);
}

/* 21L03.c: Wczytywanie i zapis wiersz po wierszu */

#include <stdio.h>

enum { SUKCES, FIASKO, MAX_LEN = 81 }; /* maks. dlugosc 81 znakow */

void lineReadWrite(FILE *plik_we, FILE *plik_wy);

int main(void) {

    FILE *fptr1, *fptr2;

    char filename1[] = "plik_wy.txt";
    char filename2[] = "plik_we.txt";
    int reval = SUKCES;

    if((fptr1 = fopen(filename1, "w")) == NULL) {
        printf("Nie moge otworzyc pliku: %s \n", filename1);
        reval = FIASKO;
    } else if((fptr2 = fopen(filename2, "r")) == NULL) {
        printf("Nie moge otworzyc pliku: %s \n", filename1);
        reval = FIASKO;
    } else {
        lineReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
    }

    return reval;
}

void lineReadWrite(FILE *plik_we, FILE *plik_wy) {
    char buff[MAX_LEN]; /* bufor na 81 znakow */

    /* dopoki funkcja fgets() nie zwroci wskaznika pustego */
    while(fgets(buff, MAX_LEN, plik_we) != NULL) {

        fputs(buff, plik_wy);
        printf("%s", buff);
    }
}

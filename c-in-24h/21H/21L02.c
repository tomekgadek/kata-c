/* 21L02.c: Odczyt i zapis z/do pliku znak-po-znaku */

#include <stdio.h>

void charReadWrite(FILE *plik_we, FILE *plik_wy);

enum { SUKCES, FIASKO };

int main(void) {

    FILE *fptr1, *fptr2;

    char filename1[] = "plik_wy.txt";
    char filename2[] = "plik_we.txt";
    int reval = SUKCES;

    if((fptr1 = fopen(filename1, "w")) == NULL) {
        printf("Nie moge otworzyc pliku: %s \n", filename1);
        reval = FIASKO;
    } else if((fptr2 = fopen(filename2, "r")) == NULL) {
        printf("Nie moge otworzyc pliku: %s \n", filename2);
        reval = FIASKO;
    } else {
        charReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
    }

    return reval;
}

void charReadWrite(FILE *plik_we, FILE *plik_wy) {
    int c;

    while((c = fgetc(plik_we)) != EOF) {
        putchar(c); /* to wyprowadzenie znaku na ekran. */
        fputc(c, plik_wy);
    }
}

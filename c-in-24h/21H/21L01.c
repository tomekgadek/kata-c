/* 21L01.c: Otwieranie i zamykanie pliku */

#include <stdio.h>

enum { SUKCES, FIASKO };

int main(void) {

    FILE *fptr;
    char filename[] = "plik.txt";
    int zwrot_z_main = SUKCES;

    if((fptr = fopen(filename, "r")) == NULL) {
        printf("Nie moge otworzyc pliku: %s \n", filename);
        zwrot_z_main = FIASKO;
    } else {
        printf("Wartosc wskaznika fptr: %p\n", fptr);
        if(fclose(fptr) == 0)
            printf("Plik zamkniety! \n");
    }

    return zwrot_z_main;
}

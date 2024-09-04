/* 22L02.c: Odczyt i zapis danych binarnych */

#include <stdio.h>

/* 0, 1, 3 */
enum { SUKCES, FIASKO, MAX_NUM = 3 };

void zapisDanych(FILE *plik_wy);
void odczytDanych(FILE *plik_we);
int errorMsg(char *str);

int main(void) {

    FILE *fptr;
    char nazwapliku[] = "binarny.plk";
    int zwrotdoSO = SUKCES;

    if((fptr = fopen(nazwapliku, "wb+")) == NULL) {
        zwrotdoSO = errorMsg(nazwapliku);
    } else {
        zapisDanych(fptr);
        rewind(fptr);
        odczytDanych(fptr);
        fclose(fptr);
    }

    return zwrotdoSO;
}

void zapisDanych(FILE *plik_wy) {

    int i;
    double bufor[MAX_NUM] = { 123.45, 567.89, 100.11 };

    printf("Rozmiar bufora: %lu-bajty \n", sizeof(bufor));
    for(i = 0; i < MAX_NUM; i++) { /* zapisz 3 elementy do pliku */

        printf("%5.2f \n", bufor[i]);
        fwrite(&bufor[i], sizeof(double), 1, plik_wy);
    }
}

void odczytDanych(FILE *plik_we) {

    int i;
    double x;

    printf("Czytam z pliku binarnego: \n");
    for(i = 0; i < MAX_NUM; i++) {
    
        fread(&x, sizeof(double), (size_t)1, plik_we);
        printf("%5.2f \n",x);
    }
}

int errorMsg(char *str) {

    printf("Nie moge otworzyc pliku: %s \n", str);
    return FIASKO;
}

/* 22L01.c: Swobodny dostep do pliku */

#include <stdio.h>

enum { SUCCESS, FAIL, MAX_LEN = 80 };

/* deklaracje funkcji */
void ptrSeek(FILE *fptr);   /* Ustaw znacznik */
long ptrTell(FILE *fptr);   /* Podaj pozycje znacznika */
void dataRead(FILE *fptr);  /* Czytaj dane z pliku */
int errorMsg(char *str);    /* Komunikat o bledzie */

int main(void) {

    FILE *fptr;
    char filename[] = "plik_we.txt";
    int reval = SUCCESS;

    if((fptr = fopen(filename, "r")) == NULL) {

        reval = errorMsg(filename);
    } else {

        ptrSeek(fptr);
        fclose(fptr);
    }

    return reval;
}

void ptrSeek(FILE *fptr) {

    long offset1, offset2, offset3;

    offset1 = ptrTell(fptr);
    dataRead(fptr);
    offset2 = ptrTell(fptr);
    dataRead(fptr);
    offset3 = ptrTell(fptr);
    dataRead(fptr);

    printf("\nCzytam od tylu: \n");

    fseek(fptr, offset3, SEEK_SET);
    dataRead(fptr);
    fseek(fptr, offset2, SEEK_SET);
    dataRead(fptr);
    fseek(fptr, offset1, SEEK_SET);
    dataRead(fptr);

    printf("\nCzytam od przypadkowego miejsca: \n");

    fseek(fptr, -15L, SEEK_END);
    dataRead(fptr);
}

long ptrTell(FILE *fptr) {

    long reval;
    reval = ftell(fptr);
    printf("Pozycja znacznika w pliku: %ld \n", reval);

    return reval;
}

void dataRead(FILE *fptr) {

    char buff[MAX_LEN];

    fgets(buff, MAX_LEN, fptr);
    printf("---%s", buff);
}

int errorMsg(char *str) {

    printf("Nie moge otworzyc pliku: %s", str);
    return FAIL;
}

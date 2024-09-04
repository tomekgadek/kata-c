/* 22L03.c: Zastosowanie funkcji fscanf() i fprintf() */

#include <stdio.h>

enum { SUCCESS, FAIL, MAX_NUM = 3, STR_LEN = 23 };

void dataWrite(FILE *fout);
void dataRead(FILE *fin);
int errorMsg(char *str);

int main(void) {

    FILE *fptr;
    char filename[] = "strnum.mix";
    int reval = SUCCESS;

    if((fptr = fopen(filename, "w+")) == NULL)
        reval = errorMsg(filename);
    else {
        dataWrite(fptr);
        rewind(fptr);
        dataRead(fptr);
        fclose(fptr);
    }

    return reval;
}

void dataWrite(FILE *fout) {

    int i;
    char cities[MAX_NUM][STR_LEN] = {
        "St.Louis->Houston:",
        "Houston->Dallas:",
        "Dallas->Philadelfia:"
    };

    int miles[MAX_NUM] = {
        845,
        243,
        1459
    };

    printf("Dane wpisane: \n");
    for(i = 0; i < MAX_NUM; i++) {
        printf("%-23s %d\n", cities[i], miles[i]);
        fprintf(fout, "%s %d\n", cities[i], miles[i]);
    }
}

void dataRead(FILE *fin) {

    int i, miles;
    char cities[STR_LEN];

    printf("\nOdczyt danych\n");
    for(i = 0; i < MAX_NUM; i++) {
        fscanf(fin, "%s%d", cities, &miles);
        printf("%-23s %d \n", cities, miles);
    }
}

int errorMsg(char *str) {

    printf("Nie moge otworzyc pliku: %s \n", str);
    return FAIL;
}

/* 21L04.c: Zapis i odczyt bloku znakow */

#include <stdio.h>

enum { SUKCES, FIASKO, MAX_LEN = 80 };

void blockReadWrite(FILE *fin, FILE *fout);
int errorMsg(char *str);

int main(void) {

    FILE *fptr1, *fptr2;

    char filename1[] = "plik_wy.txt";
    char filename2[] = "plik_we.txt";
    int reval = SUKCES;

    if((fptr1 = fopen(filename1, "w")) == NULL) {
        reval = errorMsg(filename1);
    } else if((fptr2 = fopen(filename2, "r")) == NULL) {
        reval = errorMsg(filename2);
    } else {
        blockReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
    }

    return reval;
}

void blockReadWrite(FILE *fin, FILE *fout) {
    int num;
    char buff[MAX_LEN + 1];

    while(!feof(fin)) {

        num = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num * sizeof(char)] = '\0';
        printf("%s", buff);
        fwrite(buff, sizeof(char), num, fout);
    }
}

int errorMsg(char *str) {

    printf("Nie moge otworzyc: %s \n", str);
    return FIASKO;
}

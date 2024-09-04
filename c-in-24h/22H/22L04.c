/* 22L04.c: Skierowanie standardowego strumienia stdout do pliku dyskowego */

#include <stdio.h>

enum { SUCCESS, FAIL, STR_NUM = 4 };

void strPrint(char **str); /* Uwaga: **str - to wskaznik do wskaznika */
int errorMsg(char *str);

int main(void) {

    char *str[STR_NUM] = {
        "Badz gietki a pozostaniesz silny... 1 wiersz",
        "Drugi wiersz tekstu. ",
        "Trzeci wiersz tekstu. ",
        "Czwarty wiersz --- np.Autor. "
    };
    
    char filename[] = "LaoTzu.txt";
    int reval = SUCCESS;

    strPrint(str); /* drukowanie 1 raz */

    if(freopen(filename, "w", stdout) == NULL) {
        reval = errorMsg(filename);
    } else {
        strPrint(str); /* drukowanie 2 raz */
        fclose(stdout);
    }

    return reval;
}

void strPrint(char **str) {

    int i;
    for(i = 0; i < STR_NUM; i++) {

        printf("%s\n",str[i]);
    }
}

int errorMsg(char *str) {
    printf("Nie moge otworzyc pliku: %s \n", str);
    return FAIL;
}

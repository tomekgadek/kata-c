/*
    r12z05.c: Wyświetlanie sekwencyjne wierszy z plików

    5. Napisz program, który otwiera dwa pliki o nazwach podanych w wierszu 
    poleceń.

    a. Program powinien wyświetlać 1. wiersz pierwszego pliku, 1. wiersz 
    drugiego pliku, 2. wiersz pierwszego pliku, 2. wiersz drugiego 
    pliku, i tak dalej, aż do momentu wyświetlenia ostatniego wiersza pliku 
    zawierającego większą ilość wierszy.
    b. Zmodyfikuj program z punktu a. tak, aby wiersze o tym samym numerze 
    były wyświetlane w tym samym wierszu.
*/

#include <stdio.h>
#include <string.h>

#define LINE 256
#define MODE_5B 0  // 0 = version 5a, 1 = version 5b

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Sposob uzycia: %s plik1 plik2 \n", argv[0]);
        return 1;
    }

    FILE * f1 = fopen(argv[1], "r");
    FILE * f2 = fopen(argv[2], "r");

    if (f1 == NULL || f2 == NULL) {
        printf("Problem z otwarciem plikow. \n");
        if (f1 != NULL) {
            fclose(f1);
        }
        if (f2 != NULL) {
            fclose(f2);
        }
        return 2;
    }

    char buf1[LINE], buf2[LINE];
    char *res1 = NULL, *res2 = NULL;

    while (1) {
        res1 = fgets(buf1, LINE, f1);
        res2 = fgets(buf2, LINE, f2);

        if (res1 == NULL && res2 == NULL) {
            break;
        }

#if MODE_5B
        if (res1 != NULL) {
            buf1[strlen(buf1) - 1] = '\0';
            printf("%s", buf1);
        }

        if (res2 != NULL) {
            buf2[strlen(buf2) - 1] = '\0';
            printf(" %s", buf2);
        }

        printf("\n");
#else
        if (res1 != NULL) {
            printf("%s", buf1);
        }

        if (res2 != NULL) {
            printf("%s", buf2);
        }
#endif
    }

    fclose(f1);
    fclose(f2);

    printf("\n");

    return 0;
}

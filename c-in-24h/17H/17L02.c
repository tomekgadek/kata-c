/* 17L02.c: Zastosowanie funkcji free() */

#include <stdio.h>
#include <stdlib.h>

/* deklaracje 2 funkcji */
void dataMultiply(int max, int *ptr);
void tablePrint(int max, int *ptr);

int main(void) {

    int *ptr_int, max = 0;
    int termination = 0;
    char key = 'c';

    while(key != 'x') {
        
        printf("Wpisz liczbe jednocyfrowa:\n");
        scanf("%d", &max);
        
        /* wywolanie malloc */
        ptr_int = malloc(max * max * sizeof(int));
        if(ptr_int != NULL) {
            dataMultiply(max, ptr_int);
            tablePrint(max, ptr_int);
            free(ptr_int);
            termination = 0;
        } else {
            printf("Funkcja malloc() nie przydzielila pamieci.\n");
            termination = 1;
            break;
        }
        
        printf("\nKlawisz [x] = Koniec, dowolny klawisz - kontynuuj.\n");
        scanf("%s", &key);
    }
    printf("\nKoniec!\n");
    return termination;
}

/* definicja funkcji */
void dataMultiply(int max, int *ptr) {
        int i, j;
        for(i = 0; i < max; i++)
            for(j = 0; j < max; j++)
                *(ptr + i * max + j) = (i + 1) * (j + 1);
}

/* definicja funkcji*/
void tablePrint(int max, int *ptr) {

    int i, j;
    printf("Tabliczka mnozenia %d x %d to:\n", max, max);
    printf("   ");
    for(i = 0; i < max; i++)
        printf("%4d", i+1);
    printf("\n   ");

    for(i = 0; i < max; i++)
        printf("----");

    for(i = 0; i < max; i++) {
        printf("\n%2d|", i+1);

        for(j = 0; j < max; j++)
            printf("%4d", *(ptr + i * max + j));
    }
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    double * wsd;
    int max;
    int liczba;
    int i = 0;

    puts("Ile wynosi maksymalna liczba pozycji typu double?");
    scanf("%d", &max);
    wsd = (double *) malloc(max * sizeof (double));

    if (wsd == NULL) {

        puts("Blad przydzialu pamieci. Do widzenia.");
        exit(EXIT_FAILURE);
    }

    /* wsd wskazuje teraz na tablice max elementow */
    puts("Wpisuj kolejne wartosci (q konczy program):");
    while (i < max && scanf("%lf", &wsd[i]) == 1)
        ++i;

    printf("Oto lista %d pozycji:\n", liczba = i);
    for (i = 0; i < liczba; i++) {

        printf("%7.2f ", wsd[i]);
        if (i % 7 == 6)
            putchar('\n');
    }

    if (i % 7 != 0)
        putchar('\n');
    puts("Koniec.");

    free(wsd);

    return 0;
}

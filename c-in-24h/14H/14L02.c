/* 14L02.c: Porownanie zakresow program scope - kontra - block scope */

#include <stdio.h>

int x = 1234;           /* zmienna globalna */
double y = 1.234567;    /* zmienna globalna */

void funkcja1() {
    printf("Wewnatrz funkcji1:\n x = %d, y = %f\n", x, y);
}

int main(void) {

    int x = 4321;       /* zasieg - blokowo */

    funkcja1();
    printf("Glowny blok, funkcja main():\n x = %d, y = %f\n", x, y);
    
    { /* poczatek bloku zagniezdzonego (2) */

        double y = 7.654321; /* block skope 2 */
        funkcja1();
        printf("Fun.main(), blok zagniezdzony:\n x = %d, y = %f\n", x, y);
    } /* koniec bloku zagniezdzonego */

    return 0;
}

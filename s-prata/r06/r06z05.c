/*
    r06z05.c: Wyświetlanie tabeli

    5. Napisz program, wyświetlający tabelę. Każdy wiersz tabeli powinien 
    zawierać liczbę całkowitą, jej kwadrat oraz jej sześcian. Dolna i górna 
    granica tabeli powinna być określana przez użytkownika. 
    Skorzystaj z pętli for.
*/

#include <stdio.h>

int main(void) {

    int n_start = 0;
    int n_stop = 0;

    printf("Podaj dolna granice: ");
    scanf("%d", &n_start);

    printf("Podaj gorna granice: ");
    scanf("%d", &n_stop);

    printf("+--------------------------+ \n");
    printf("|n       |n^2     |n^3     | \n");
    printf("+--------------------------+ \n");

    for(int i = n_start; i <= n_stop; i++) {

        printf("|%-8d|%-8d|%-8d| \n", i, i*i, i*i*i);
    }

    printf("+--------------------------+ \n");

    return 0;
}

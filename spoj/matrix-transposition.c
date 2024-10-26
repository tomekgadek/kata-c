/*
    matrix-transposition.c: TRN - Transponowanie macierzy

    Zadanie: https://pl.spoj.com/problems/TRN/

    Kompilacja oraz uruchomienie programu: gcc matrix-transposition.c && ./a.out < ./tests/matrix-transposition-tests.txt
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m = 0, n = 0;

    scanf("%d %d", &m, &n);

    int **matrix = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++ ) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    for(int i = 0; i < m; i++ ) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < m; j++ ) {
            printf( "%d ", matrix[j][i] );
        }

        printf( "\n" );
    }

    for(int i = 0; i < m; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}

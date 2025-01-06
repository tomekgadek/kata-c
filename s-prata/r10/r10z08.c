/*
    r10z08.c: Sumowanie tablic

    8. Napisz funkcję, która przypisuje każdemu elementowi tablicy sumę 
    wartości odpowiednich elementów w dwóch innych tablicach. (Jeśli tablica 
    nr 1 ma wartości 2, 4, 5 i 8, a tablica nr 2 wartości 1, 0, 4 i 6, funkcja 
    przypisuje tablicy nr 3 wartości 3, 4, 9 i 14.) Funkcja powinna przyjmować 
    jako argumenty trzy nazwy tablic oraz ich rozmiar. 
    Wypróbuj funkcję w prostym programie.
*/

#include <stdio.h>

#define ARRAY_SIZE 4

void sum_arrays(int[], int[], int[], int);

int main(void) {

    int first_array[ARRAY_SIZE]  = { 2, 4, 5, 8 };
    int second_array[ARRAY_SIZE] = { 1, 0, 4, 6 };
    int result_array[ARRAY_SIZE];

    sum_arrays(result_array, first_array, second_array, ARRAY_SIZE);

    printf("( A ) + ( B ) = ( RESULT ) \n");
    for(int i = 0; i < ARRAY_SIZE; i++) {

        printf("  %d   +   %d   = %5d \n", 
            first_array[i], second_array[i], result_array[i]);
    }

    return 0;
}

void sum_arrays(int result[], int a[], int b[], int size) {

    for(int i = 0; i < size; i++) {
        result[i] = a[i] + b[i];
    }
}

/*
    r10z06.c: Kopiowanie tablic dwuwymiarowych

    6. Napisz program, który inicjalizuje tablicę dwuwymiarową i kopiuje ją do 
    innej tablicy dwuwymiarowej korzystając z jednej z funkcji z ćwiczenia 2. 
    (Ponieważ tablica dwuwymiarowa jest tablicą tablic, jednowymiarowa 
    funkcja kopiująca może być stosowana do poszczególnych podtablic.)
*/

#include <stdio.h>

#define COLUMNS 2
#define ROWS    3

void copy_array(const int [], int [], int);
void show_array(int [][COLUMNS], int);

int main(void) {

    int array[ROWS][COLUMNS] = { { 5, 6 } , { 1, 2 } , { 0, 11 } };
    int array_c[ROWS][COLUMNS];
        
    for(int i = 0; i < ROWS; i++) {
        copy_array(array[i], array_c[i], COLUMNS);
    }

    printf("main array: \n");
    show_array(array, ROWS);
        
    printf("copy array: \n");
    show_array(array_c, ROWS);

    return 0;
}

void copy_array(const int start[], int stop[], int size) {

    int *end_addr = (int *)(start + size);

    while(start < end_addr) {
        *stop++ = *start++;
    }
}

void show_array(int array[][COLUMNS], int row) {
        
    for(int i = 0; i < row; i++) {

        for(int j = 0; j < COLUMNS; j++) {
            printf("%3d", array[i][j]);
        }

        printf("\n");
    }
}

/*
    r10z02.c: Kopiowanie tablic

    2. Napisz program, który inicjalizuje tablicę, a następnie kopiuje jej 
    zawartość do dwóch innych tablic. (Wszystkie trzy tablice powinny być 
    zadeklarowane w głównym programie.) Do wykonania pierwszej kopii użyj 
    funkcji wykorzystującej notację tablicową. Do wykonania drugiej kopii 
    użyj funkcji wykorzystującej zapis wskaźnikowy i zwiększanie wskaźników. 
    Każda funkcja powinna przyjmować jako argumenty nazwę tablicy 
    źródłowej, nazwę tablicy docelowej oraz rozmiar tablic.
*/

#include <stdio.h>

#define ARRAY_SIZE 7

void copy_use_array_notation(int from[], int to[], int size);
void copy_use_pointer_notation(int *from, int *to, int size);

int main(void) {

    int digits[ARRAY_SIZE] = { 2, 1, 5, 6, 2, 7, 0 };
    int first_copy[ARRAY_SIZE];
    int second_copy[ARRAY_SIZE];

    copy_use_array_notation(digits, first_copy, ARRAY_SIZE);
    copy_use_pointer_notation(digits, second_copy, ARRAY_SIZE);

    printf("array(1) array(2) array(3) \n");
    for(int i = 0; i < ARRAY_SIZE; i++) {

        printf("%-8d %-8d %-8d \n", digits[i], first_copy[i], second_copy[i]);
    }

    return 0;
}

void copy_use_array_notation(int from[], int to[], int size) {

    for(int i = 0; i < size; i++) {

        to[i] = from[i];
    }
}

void copy_use_pointer_notation(int *from, int *to, int size) {

    for(int i = 0; i < size; i++) {

        *(to + i) = *(from + i);
    }
}

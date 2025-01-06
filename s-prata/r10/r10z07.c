/*
    r10z07.c: Kopiowanie wybranych elementów

    7. Użyj funkcji kopiującej z ćwiczenia 2 do skopiowania od trzeciego do 
    piątego elementu 7- elementowej tablicy. Elementy powinny zostać 
    umieszczone w tablicy 3-elementowej. Sama funkcja nie musi być 
    modyfikowana; wystarczy dobrać odpowiednie argumenty faktyczne. 
    (Argumentami nie muszą być nazwa tablicy i jej rozmiar - równie dobrze 
    przekazać można adres jednego z elementów oraz liczbę elementów 
    do skopiowania.)
*/

#include <stdio.h>

#define ARRAY_SIZE      7
#define ARRAY_DEST_SIZE 3

void copy_use_pointer_notation(int *from, int *to, int size);

int main(void) {

    int digits[ARRAY_SIZE] = { 2, 1, 5, 6, 2, 7, 0 };
    int digits_copy[ARRAY_DEST_SIZE];

    copy_use_pointer_notation(&digits[2], &digits_copy[0], ARRAY_DEST_SIZE);

    printf("array(1): ");
    for(int i = 0; i < ARRAY_SIZE; i++) {

        printf("%-3d", digits[i]);
    }

    printf("\narray(2): ");
    for(int i = 0; i < ARRAY_DEST_SIZE; i++) {

        printf("%-3d", digits_copy[i]);
    }

    printf("\n");

    return 0;
}

void copy_use_pointer_notation(int *from, int *to, int size) {

    for(int i = 0; i < size; i++) {

        *(to + i) = *(from + i);
    }
}

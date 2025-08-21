/*
    r13z05.c: Generowanie i sortowanie liczb losowych

    5. Napisz program, który generuje listę 100 liczb losowych z przedziału 
    1-10 i wyświetla ją w kolejności malejącej.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIGITS_SIZE 100
#define RAND_FROM 1
#define RAND_TO 10

void sort(int [], int);
int * draw(int [], int, int, int);
void show(const int [], int);

int main(void) {

    int digits[DIGITS_SIZE];

    int *drawn_digits = draw(digits, DIGITS_SIZE, RAND_FROM, RAND_TO);

    printf("Wylosowane liczby: \n");
    show(drawn_digits, DIGITS_SIZE);

    printf("Liczby w kolejnosci malejacej: \n");

    sort(drawn_digits, DIGITS_SIZE);
    show(drawn_digits, DIGITS_SIZE);
    
    return 0;
}

void sort(int digits[], int size) {

    for (int i = 0; i < size - 1; i++) {

        int max_index = i;
        for (int j = i + 1; j < size; j++) {

            if (digits[max_index] < digits[j]) {
                max_index = j;
            }
        }

        int swap = digits[i];
        digits[i] = digits[max_index];
        digits[max_index] = swap;
    }
}

int * draw(int digits[], int size, int rand_from, int rand_to) {

    srand((unsigned int) time(0));

    for(int i = 0; i < size; i++) {
        digits[i] = (rand() % rand_to) + rand_from;
    }

    return &digits[0];
}

void show(const int digits[], int size) {
    
    for(int i = 0; i < size; i++) {
        printf("%-3d", digits[i]);

        if(i % 10 == 9) {
            printf("\n");
        }
    }

    printf("\n");
}

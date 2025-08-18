/*
    r13z02.c: Sortowanie liczb zmiennoprzecinkowych

    2. Napisz program, który porządkuje liczby typu float w kolejności rosnącej.
*/

#include <stdio.h>

#define SIZE 10

void sort(float [], int size);
void show(const float [], int size);

int main(void) {

    float digits[SIZE] = { 
        3.2f, 7.8f, 1.5f, 9.0f, 4.4f, 
        2.1f, 8.6f, 5.5f, 0.9f, 6.3f 
    };

    sort(digits, SIZE);
    show(digits, SIZE);

    return 0;
}

void sort(float digits[], int size) {

    float swap = 0.0f;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (digits[i] >= digits[j]) {
                swap = digits[i];
                digits[i] = digits[j];
                digits[j] = swap;
            }
        }
    }
}

void show(const float digits[], int size) {

    printf("Wynik sortowania: \n");

    for (int i = 0; i < size; i++) {
        printf("%-4.1f", digits[i]);

        if(i % 5 == 4) {
            printf("\n");
        }
    }
}

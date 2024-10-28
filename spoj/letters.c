/*
    letters.c: AL_14_01 - Literki

    Zadanie: https://pl.spoj.com/problems/AL_14_01/

    Kompilacja oraz uruchomienie programu: gcc letters.c && ./a.out < ./tests/letters-tests.txt
*/
#include <stdio.h>
#include <math.h>

#define ALL_LETTERS 26
#define A           'A'
#define Z           'Z'

void show_histogram(int *, int, int);
void print_stars(int);

int main(void) {

    int histogram[ALL_LETTERS];

    for(int i = 0; i < ALL_LETTERS; i++) {
        histogram[i] = 0;
    }

    char sign = '_';
    int sign_counter = 0;
    while((sign = getc(stdin)) != '\n') {

        if(sign >= A && sign <= Z) {
            sign_counter += 1;
            histogram[sign - A] += 1; // A = 65
        }
    }

    show_histogram(histogram, ALL_LETTERS, sign_counter);

    return 0;
}

void show_histogram(int *histogram, int size, int sign_counter) {

    const double PERCENT_100 = 100.0;
    
    double frequency = 0.0;
    for(int i = 0; i < size; i++) {

        frequency = round(histogram[i] / (double)sign_counter * PERCENT_100);
        putchar(A + i); // A(65) + i
        print_stars((int)frequency);
        putchar('\n');
    }
}

void print_stars(int size) {
    while(size--) {
        putchar('*');
    }
}

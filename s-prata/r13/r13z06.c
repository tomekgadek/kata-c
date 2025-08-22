/*
    r13z06.c: Generowanie i zliczanie liczb losowych

    6. Napisz program, który generuje 1000 liczb losowych z przedziału 1-10, a 
    następnie wyświetla liczbę razy, jaką została wylosowana każda z liczb od 
    0 do 10. Program powinien wykonać to zadanie dla dziesięciu różnych 
    wartości ziarna. Czy digits pojawiają się w jednakowych ilościach? 
    Uzyskanie odpowiedzi na to pytanie jest jednym ze sposobów na 
    przetestowanie losowości określonego generatora liczb losowych. (Możesz 
    skorzystać z funkcji z tego rozdziału lub ze standardowych funkcji rand() 
    i srand() – w obu przypadkach zasada działania jest taka sama.)
*/

#include <stdio.h>
#include <stdlib.h>

#define DIGITS_SIZE 1000
#define DIGITS_COUNTER_SIZE 10
#define RAND_FROM 1
#define RAND_TO 10

int * draw(int [], int, int, int, int);
int * count_digits(const int [], int, int [], int, int, int);
void show(const int [], int);

int main(void) {

    int digits[DIGITS_SIZE];
    int digits_counter[DIGITS_COUNTER_SIZE];

    for(int seed = 0; seed < 10; seed++) {

        int *drawn_digits = draw(digits, DIGITS_SIZE, RAND_FROM, RAND_TO, seed);
        
        printf("Dla ziarna: %d \n", seed);
        
        count_digits(drawn_digits, DIGITS_SIZE, digits_counter, DIGITS_COUNTER_SIZE, RAND_FROM, RAND_TO);
        show(digits_counter, DIGITS_COUNTER_SIZE);
    }

    return 0;
}

int * draw(int digits[], int size, int rand_from, int rand_to, int seed) {

    srand(seed);

    for(int i = 0; i < size; i++) {
        digits[i] = (rand() % rand_to) + rand_from;
    }

    return &digits[0];
}

int * count_digits(const int digits[], int digits_size, int digits_counter[], int digits_counter_size, int from, int to) {

    for(int i = 0; i < digits_counter_size; i++) {
        digits_counter[i] = 0;
    }

    for(int i = 0; i < digits_size; i++) {
        if(digits[i] >= from && digits[i] <= to) {

            int draw_value = digits[i];
            digits_counter[draw_value-1]++;
        }
    }

    return &digits_counter[0];
}

void show(const int digits_counter[], int digits_counter_size) {

    for(int i = 0; i < digits_counter_size; i++) {
        printf("%d wystepuje %d razy. \n", i+1, digits_counter[i]);
    }
}

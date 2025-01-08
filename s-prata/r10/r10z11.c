/*
    r10z11.c: Operacje na tablicy dwuwymiarowej

    11. Napisz program, który prosi użytkownika o podanie trzech zbiorów 
    składających się z pięciu liczb typu double, a następnie:

    a. Zapisuje te dane w tablicy o wymiarach 3 na 5.
    b. Oblicza średnią dla każdego zbioru z osobna.
    c. Oblicza średnią dla wszystkich wartości.
    d. Znajduje największą spośród 15 wartości.
    e. Wyświetla wyniki.

    Każde podstawowe zadanie powinno być wykonywane przez oddzielną funkcję.
*/

#include <stdio.h>

const int ROWS = 3;
const int COLS = 5;

void insert(double data[][COLS], int rows);
void avg_rows(double data[][COLS], int rows);
double avg(double data[][COLS], int rows);
double max(double data[][COLS], int rows);
void show(double data[][COLS], int rows);

int main(void) {

    double digits[ROWS][COLS];

    insert(digits, ROWS);
    avg_rows(digits, ROWS);
    
    double avg_value = avg(digits, ROWS);
    printf("Srednia wynosi %.2lf \n", avg_value);

    double max_value = max(digits, ROWS);
    printf("Wartosc maksymalna wynosi %.2lf \n", max_value);

    show(digits, ROWS);

    return 0;
}

void insert(double data[][COLS], int rows) {

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < COLS; j++) {
            printf("A(%d, %d): ", i, j);
            scanf("%lf", &data[i][j]);
        }
    }
}

void avg_rows(double data[][COLS], int rows) {

    for(int i = 0; i < rows; i++) {

        double sum = 0.0;
        for(int j = 0; j < COLS; j++) {

            sum += data[i][j];
        }

        printf("Srednia zbioru %d = %.2lf \n", i, sum / (double) COLS);
    }
}

double avg(double data[][COLS], int rows) {

    double sum = 0.0;

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < COLS; j++) {

            sum += data[i][j];
        }
    }

    return sum / (double)(COLS * rows);
}

double max(double data[][COLS], int rows) {

    double max_value = data[0][0];

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < COLS; j++) {

            if(max_value < data[i][j]) {

                max_value = data[i][j];
            }
        }
    }

    return max_value;
}

void show(double data[][COLS], int rows) {

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < COLS; j++) {

            printf("%-5.2lf", data[i][j]);
        }

        printf("\n");
    }
}

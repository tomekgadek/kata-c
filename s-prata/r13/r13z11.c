/*
    r13z11.c: Sortowanie wierszy z pliku tekstowego według średniej

    11. Skonstruuj plik tekstowy składający się z dziesięciu wierszy, z których 
    każdy zawiera imię, dwukropek oraz trzy liczby całkowite. Napisz 
    program, który odczytuje ten plik i wyświetla wiersze w rosnącym porządku 
    określonym średnią wartością liczb całkowitych. Wiersz
    ```bash
        Mata Hari: 80 70 84
    ```
    znalazłby się przed wierszem

    ```bash
        Hans Christian Andersen: 70 90 80
    ```
    ponieważ średnia jego trzech wartości jest mniejsza niż średnia wartości 
    wiersza drugiego. Ponadto, program powinien wyświetlać każdy wiersz 
    razem z jego średnią. Zauważ, że tekstowa część wiersza nie musi składać 
    się z dokładnie dwóch słów.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMBER_OF_LINES 10
#define DATA_SIZE 1024
#define FILENAME "static/database.txt"

int load_database(char *filename, char *users[], int number_of_lines);
void delete_database(char *users[], int number_of_lines);
double *insert_averages(char *users[], double averages[], int data_size);
void show(char *users[], double averages[], int data_size);
void sort(char *users[], double averages[], int data_size);

int main(void) {

    double avg[NUMBER_OF_LINES];
    char *database[NUMBER_OF_LINES];

    int read_lines = load_database(FILENAME, database, NUMBER_OF_LINES);
    insert_averages(database, avg, read_lines);
    sort(database, avg, read_lines);
    show(database, avg, read_lines);
    delete_database(database, read_lines);

    return 0;
}

int load_database(char *filename, char *users[], int number_of_lines) {
    const int data_size = 1024;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Nie mozna otworzyc pliku %s\n", filename);
        exit(1);
    }

    int read_lines = 0;
    char line[data_size];
    for(int i = 0; fgets(line, data_size, file) != NULL; i++) {
        read_lines += 1;

        users[i] = (char *)malloc((strlen(line) + 1) * sizeof(char));

        if(users[i] == NULL) {
            fprintf(stderr, "Blad alokacji pamieci dla wiersza %d\n", i);
            exit(1);
        }

        strcpy(users[i], line);

        if(i >= number_of_lines) {
            break;
        }
    }

    fclose(file);

    return read_lines;
}

void delete_database(char *users[], int number_of_lines) {

    for(int i = 0; i < number_of_lines; i++) {
        free(users[i]);
    }
}

double *insert_averages(char *users[], double averages[], int data_size) {

    int a = 0, b = 0, c = 0;

    for(int i = 0; i < NUMBER_OF_LINES; i++) {
        if (sscanf(users[i], "%*[^:]: %d %d %d", &a, &b, &c) == 3) {
            averages[i] = (a + b + c) / 3.0;
        } else {
            averages[i] = 0;
        }
    }

    return &averages[0];
}

void show(char *users[], double averages[], int data_size) {

    for(int i = 0; i < data_size; i++) {
        printf("%.2lf - %s", averages[i], users[i]);
    }
}

void sort(char *users[], double averages[], int data_size) {

    for (int i = 0; i < data_size-1; i++) {

        int max_idx = i;
        for(int j = i+1; j < data_size; j++) {
            if(averages[j] > averages[max_idx]) {
                max_idx = j;
            }
        }

        double swap_avg = averages[i];
        averages[i] = averages[max_idx];
        averages[max_idx] = swap_avg;

        char *swap_usr = users[i];
        users[i] = users[max_idx];
        users[max_idx] = swap_usr;
    }
}

/*
    r16z08.c: Program losujący liczby jak w totolotku

    8. Napisz funkcję, która przyjmuje następujące argumenty: nazwę numberslicy typu 
    int, rozmiar numberslicy oraz wartość określającą liczbę pozycji do wybrania. 
    Funkcja w sposób losowy wybiera z numberslicy zadaną liczbę elementów i 
    wyświetla je na ekranie. Żaden z elementów nie może zostać wybrany więcej 
    niż raz (tak jak przy wyborze liczb w totolotku lub członków zespołu 
    sędziowskiego). Ponadto, jeśli Twoja implementacja zawiera funkcję time() 
    (omówioną w Rozdziale 13 "Klasy zmiennych i opracowywanie programu") lub 
    podobną, użyj zwróconej przez nią wartości do zainicjalizowania generatora 
    liczb losowych (za pomocą funkcji srand()). Napisz prosty program testujący 
    funkcję.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void lottery(const int numbers[], int size, int picks);

int main(void) {

    const int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers) / sizeof(const int);
    int picks = 5;

    lottery(numbers, size, picks);

    return 0;
}

void lottery(const int numbers[], int size, int picks) {

    if (picks > size || picks <= 0) {
        printf("Liczba losowanych pozycji jest nieprawidłowa.\n");
        return ;
    }

    int *selected = (int *)calloc(size, sizeof(int));
    if (selected == NULL) {
        fprintf(stderr, "Błąd przydziału pamięci.\n");
        return ;
    }

    srand((unsigned int)time(NULL));

    for (int i = 0; i < picks; ) {

        int index = rand() % size;
        if (selected[index] == 0) {
            selected[index] = 1;
            i++;
        }
    }

    printf("Wylosowane liczby: ");

    for(int i = 0; i < size; i++) {

        if(selected[i]) {
            printf("%d ", numbers[i]);
        }
    }

    printf("\n");

    free(selected);
}

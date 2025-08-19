/*
    r13z03.c: Modyfikacja funkcji sort()

    3. Zmodyfikuj funkcję sort() z listingu 13.12 stosując zalecenie 
    sformułowane w sekcji "Komentarz" (znajdziesz ją po przykładowych wynikach 
    działania programu sortującego): Funkcja powinna zapamiętywać indeks 
    największej wartości i dokonywać zamiany dopiero po zakończeniu pętli 
    wewnętrznej. 
*/

#include <stdio.h>

#define MAX 10

void sort(int[], int);
void wyswietl(const int[], int);

int main(void) {

    int liczby[MAX] = { 34, -7, 12, 56, 0, 23, 89, -15, 42, 8 };

    sort(liczby, MAX);
    wyswietl(liczby, MAX);

    return 0;
}

void sort(int tablica[], int granica) {

    for (int gora = 0; gora < granica - 1; gora++) {

        int max_index = gora;
        for (int szuk = gora + 1; szuk < granica; szuk++) {
            if (tablica[max_index] < tablica[szuk]) {
                max_index = szuk;
            }
        }

        int temp = tablica[gora];
        tablica[gora] = tablica[max_index];
        tablica[max_index] = temp;
    }
}

void wyswietl(const int tablica[], int rozmiar) {

    printf("Wynik sortowania: \n");

    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", tablica[i]);
    }

    printf("\n");
}

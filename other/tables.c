/*
	Nalezy utworzyć 2 funkcje, które:
	1: Alokuje pamięć pamięć i wprowadza elementy.
	2: Wyszukuje elementy w tablicy i zwraca informację ile razy wystąpił.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Odpowiada za tworzenie tablicy dla liczb całkowitych.
 * 
 * @param size Rozmiar tablicy.
 *
 * @return Wskaźnik do utworzonej tablicy.
 */
int * create_table(int);

/**
 * Zlicza wystąpienia podanej cyfry / liczby przekazanej w parametrze.
 * 
 * @param table Wskaźnik do tablicy liczb całkowitych.
 * @param size Rozmiar przekazanej tablicy.
 * @param element Element, którego wystąpienia będą zliczane.
 *
 * @return Ilość wystąpień przekazanego elementu.
 */
int count_element(int *, int, int);

int main(void) {

	int size = 0;

	printf("Podaj rozmiar tablicy: ");
	scanf("%d", &size);

	int * digits = create_table(size);
	int element = 0;

	printf("Podaj element, w celu zliczenia wystapien: ");
	scanf("%d", &element);

	printf("%d wystapil %d raz(y)! \n", element, count_element(digits, size, element));
	
	free(digits);

	return 0;
}

int * create_table(int size) {

	int * table = (int *)malloc(size * sizeof(int));

	if(table == NULL) {
		printf("Nie mozna zaalokowac pamieci! \n");
		exit(1);
	}

	// Inicjalizacja generatora liczb pseudolosowych
	srand(time(NULL));

	
	for(int i = 0; i < size; i++) {
		table[i] = rand() % 6; // Losowanie z zakresu <0, 5>
	}
	

	return table;
}

int count_element(int *table, int size, int element) {
	int amount = 0;

	for(int i = 0; i < size; ++i) {
		if(table[i] == element) {
			amount++;
		}
	}

	return amount;
}

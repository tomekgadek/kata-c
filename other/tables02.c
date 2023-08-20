/*
	Mamy do dyspozycji plik digits.txt. Zawartość pliku to dwie linie:
	Linia 1: zawiera rozmiar tablicy
	Linia 2. zawiera liczby typu 'int' 
	Zaimplementować funkcje, która odczyta liczby z pliku do tablicy zaalokowanej 
	dynamicznie o zadanym rozmiarze, a funkcja wypisze zawartość tablicy w kolejnosci odwrotnej.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Odczytuje rozmiar tablicy z podanego pliku.
 *
 * Ta funkcja odczytuje pierwszą linię pliku, aby określić rozmiar tablicy.
 *
 * @param filename Nazwa pliku zawierającego rozmiar.
 * @return Wskaźnik do liczby całkowitej reprezentującej rozmiar tablicy.
 */
int * getTableSize(const char filename []);

/**
 * Odczytuje liczby całkowite z podanego pliku i przechowuje je w dynamicznie alokowanej tablicy.
 *
 * Ta funkcja odczytuje liczby całkowite z pliku i przechowuje je w dynamicznie alokowanej tablicy.
 *
 * @param filename Nazwa pliku zawierającego liczby całkowite.
 * @param size Rozmiar tablicy.
 * @return Wskaźnik do dynamicznie alokowanej tablicy liczb całkowitych.
 */
int * getTable(const char filename [], int size);

/**
 * Odwraca kolejność elementów w danej tablicy.
 *
 * Ta funkcja przyjmuje tablicę liczb całkowitych oraz jej rozmiar i zmienia kolejność 
 * elementów na odwrotną.
 *
 * @param digits Tablica liczb całkowitych, która ma zostać odwrócona.
 * @param size Rozmiar tablicy.
 * @return Wskaźnik do odwróconej tablicy liczb całkowitych.
 */
int * reverseTable(int digits [] , int size);

/**
 * Wyświetla zawartość tablicy.
 *
 * @param digits Tablica liczb całkowitych do wyświetlenia.
 * @param size Rozmiar tablicy.
 */
void showTable(int digits [], int size);

const char * filename = "./tmp/digits.txt";

int main(void) {

	int * size = getTableSize(filename);
	printf("Table size: %d \n", *size);

	int * digits = getTable(filename, *size);
	int * reverseDigits = reverseTable(digits, *size);
	showTable(reverseDigits, *size);

	free(size);
	free(reverseDigits);

	return 0;
}

int * getTableSize(const char filename []) {

	char * type = "r";
	FILE * file = NULL;

	int * size = (int *) malloc(sizeof(int));

	if((file = fopen(filename, type)) == NULL) {
		printf("Nie moge otorzyc pliku! \n");
		exit(1);
	}

	fscanf(file, "%d", size);

	if(fclose(file)) {
		printf("Nie moge zamknac pliku! \n");
		exit(2);
	}

	return size;
}

int * getTable(const char filename [], int size) {
	char * type = "r";
	FILE * file = NULL;

	int * digits = (int *) malloc(size * sizeof(int));

	if((file = fopen(filename, type)) == NULL) {
		printf("Nie moge otworzyc pliku! \n");
		exit(1);
	}

	fscanf(file, "%d", &digits[0]); // first line

	for(int i = 0; feof(file) == 0; i++) {
		fscanf(file, "%d", &digits[i]);
	}

	if(fclose(file)) {
		printf("Nie moge zamknac pliku! \n");
		exit(2);
	}

	return digits;
}

int * reverseTable(int digits [] , int size) {

	int i = 0;
	int j = size - 1;

	int temporaryDigit = 0;

	while(i <= j) {

		temporaryDigit = digits[i];
		digits[i] = digits[j];
		digits[j] = temporaryDigit;

		i += 1;
		j -= 1;
	}

	return digits;
}

void showTable(int digits [], int size) {

	puts("Table: ");
	for(int i = 0; i < size; i++) {
		printf("%d ", digits[i]);
	}

	puts("");
}

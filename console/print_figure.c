/*
	Program rysuje czworokat o podanych przez uzytkownika wymiarach.
*/

#include <stdio.h>

/**
 * Rysuje na standardowym wyjsciu czworokat o podanej szerokosci i wysokosci.
 * 
 * @param int heigh
 * @param int width
 */
void print_rectangle(int height, int width);

int main(void) {

	int height = 0;
	int width = 0;

	printf("Wpisz wysokosc czworokata:  ");
	scanf("%d", &height);
	printf("Wpisz szerokosc czworokata: ");
	scanf("%d", &width);

	print_rectangle(height, width);

	return 0;
}

void print_rectangle(int height, int width) {

	for(int counter = 0; counter < height; counter++) {
		for(int counter = 0; counter < width; counter++) {
			printf("o");
		}
		
		printf("\n");
	}
}

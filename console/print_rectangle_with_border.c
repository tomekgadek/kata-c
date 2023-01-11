/*
	Program rysuje obramowanie czworokata o wymiarach podanych przez uzytkownika.
*/

#include <stdio.h>

/**
 * Rysuje na standardowym wyjsciu obramowanie czworokata o podanej szerokosci i wysokosci.
 * 
 * @param heigh wysokosc czworokata.
 * @param width szerokosc czworokata.
 */
void print_rectangle_with_border(int height, int width);

int main(void) {

	int height = 0;
	int width = 0;

	printf("Wpisz wysokosc czworokata:  ");
	scanf("%d", &height);
	printf("Wpisz szerokosc czworokata: ");
	scanf("%d", &width);

	print_rectangle_with_border(height, width);

	return 0;
}

void print_rectangle_with_border(int height, int width) {

	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
            if(i == 0 || j == 0 || i == height - 1 || j == width - 1) {
			    printf("o");
            } else {
                printf(" ");
            }
		}
		
		printf("\n");
	}
}

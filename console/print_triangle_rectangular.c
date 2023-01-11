/*
	Program rysuje trojkat prostokatny o podstawie podanej przez uzytkownika.
*/

#include <stdio.h>

/**
 * Rysuje na standardowym wyjsciu trojkat prostokatny o podanej podstawie.
 * 
 * @param base
 */
void print_triangle_rectangular(int base);

int main(void) {

    int base = 13;
    print_triangle_rectangular(base);

    return 0;
}

void print_triangle_rectangular(int base) {

    for(int i = 0; i < base; i++) {
        for(int j = 0; j < i; j++) {
            printf("o");
        }

        printf("\n");
    }
}

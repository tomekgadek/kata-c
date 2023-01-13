/*
    Program rysuje trojkat rownoramienny na standardowym wyjsciu.
*/

#include <stdio.h>

/**
 * Rysuje trojkat rownoramienny na standardowym wyjsciu.
 * 
 * @param h wysokosc trojkata.
 */
void print_triangle_isosceles(int h);

int main(void) {

    int h = 7;
    print_triangle_isosceles(h);

    return 0;
}

void print_triangle_isosceles(int h) {

    int base = 1 + 2 * h;

    int half_base = base / 2 + (base % 2 == 0 ? 0 : 1);

    int point_counter = 1;
    for(int i = 0; i < h; i++) {

        for(int j = half_base; j > 0; j--) {
            printf(" ");
        }

        for(int k = 0; k < point_counter; k++) {
            printf("o");
        }

        printf("\n");

        point_counter += 2;
        half_base -= 1;
    }
}
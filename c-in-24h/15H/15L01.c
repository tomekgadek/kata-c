/* 15L01.c: Deklaracja, definicja i wywolanie funkcji */

#include <stdio.h>

int funkcja1(int x, int y); /* deklaracja funkcji 1 */

double funkcja2(double x, double y) { /* definicja funkcji 2 */

    printf("W funkcji_2.\n");
    return (x - y);
}

int main(void) {

    int x1 = 80;
    int y1 = 10;

    double x2 = 100.123456;
    double y2 = 10.123456;

    printf("Wywolanie funkcja1(%d, %d)\n", x1, y1);
    printf("funkcja1 zwraca: %d.\n", funkcja1(x1,y1)); // <- wywolanie
    printf("Wywolanie funkcja2(%f, %f)\n", x2, y2);
    printf("funkcja2 zwraca: %f.\n", funkcja2(x2,y2)); // <- wywolanie

    return 0;
}

int funkcja1(int x, int y) { /* definicja funkcji 1 */

    printf("W funkcji_1.\n");
    return (x + y);
}

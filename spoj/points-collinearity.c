/*
    points-collinearity.c: JWSPLIN - Współliniowość punktów

    Zadanie: https://pl.spoj.com/problems/JWSPLIN/

    Kompilacja oraz uruchomienie programu: gcc points-collinearity.c && ./a.out < ./tests/points-collinearity-tests.txt
*/
#include <stdio.h>

#define YES "TAK"
#define NO  "NIE"

struct Point {

    int x;
    int y;
} point_a = {0, 0}, point_b = {0, 0}, point_c = {0, 0};

int main(void) {

    int how_many_tests = 0;

    scanf("%d", &how_many_tests);

    while(how_many_tests-- > 0) {

        scanf("%d %d", &point_a.x, &point_a.y);
        scanf("%d %d", &point_b.x, &point_b.y);
        scanf("%d %d", &point_c.x, &point_c.y);

        // Wzor:
        /*
            VECT->(AB) = [Xb - Xa ; Yb - Ya]
            VECT->(AC) = [Xc - Xa ; Yc - Ya]

            Kryterium rownoleglosci wektorow:

            (Xb - Xa) * (Yc - Ya) = (Yb - Ya) * (Xc - Xa) // wtedy punkty sa wspoliniowe
        */

        int left = (point_b.x - point_a.x) * (point_c.y - point_a.y);
        int right = (point_b.y - point_a.y) * (point_c.x - point_a.x);

        printf("%s \n", left == right ? YES : NO);
    }

	return 0;
}

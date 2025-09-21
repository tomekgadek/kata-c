/*
    r16z04.c: Współrzędne kartezjańskie i biegunowe z użyciem struktur

    4. Konwersją powinna zajmować się funkcja, która pobiera strukturę zawierającą 
    współrzędne biegunowe i zwraca strukturę zawierającą współrzędne kartezjańskie 
    (jeśli wolisz, możesz użyć wskaźników do struktur).
*/

#include <stdio.h>
#include <math.h>

// Struktura przechowująca współrzędne biegunowe
typedef struct polar {
    double r;
    double A;
} Polar;

// Struktura przechowująca współrzędne kartezjańskie
typedef struct cartesian {
    double x;
    double y;
} Cartesian;

// Funkcja konwertująca stopnie na radiany
double deg2rad(double deg);

// Funkcja konwertująca współrzędne biegunowe na kartezjańskie
Cartesian * polar_to_cartesian(const Polar *p, Cartesian *c);

int main(void) {

    Polar p;
    Cartesian c;

    printf("Podaj dlugosc wektora: ");
    scanf("%lf", &p.r);
    printf("Podaj kat wektora (w stopniach): ");
    scanf("%lf", &p.A);

    polar_to_cartesian(&p, &c);

    printf("Wspolrzedne kartezjanskie wektora: \n");
    printf("x = %.2f \n", c.x);
    printf("y = %.2f \n", c.y);

    return 0;
}

double deg2rad(double deg) {
    const double PI = 3.14;
    
    return deg * (PI / 180.0);
}

Cartesian * polar_to_cartesian(const Polar *p, Cartesian *c) {
    double rad = deg2rad(p->A);
    c->x = p->r * cos(rad);
    c->y = p->r * sin(rad);

    return c;
}

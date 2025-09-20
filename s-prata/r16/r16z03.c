/*
    r16z03.c: Współrzędne kartezjańskie i biegunowe

    3. Wektor we współrzędnych biegunowych jest opisany przez długość oraz kąt 
    mierzony od osi x-ów w kierunku przeciwnym do ruchu wskazówek zegara. 
    Współrzędne kartezjańskie opisują ten sam wektor za pomocą składowych x i y 
    (patrz rys. 16.3). Napisz program, który wczytuje długość i kąt 
    (w stopniach) wektora, a następnie wyświetla wartości jego składowych x i y. 
    Oto potrzebne równania:

    x = r cos A
    y = r sin A

    
    y
    |oooooooo
    |      *o
    |     * o
    |    *  o
    |   *   o
    |  *    o
    | *  A) o
    |*      o
    *-------- x

    Rysunek 16.3 Współrzędne kartezjańskie i biegunowe.
*/

#include <stdio.h>
#include <math.h>

// Funkcja konwertująca stopnie na radiany
double deg2rad(double deg);

int main(void) {

    double r, A;

    printf("Podaj dlugosc wektora: ");
    scanf("%lf", &r);
    printf("Podaj kat wektora (w stopniach): ");
    scanf("%lf", &A);

    A = deg2rad(A);
    double x = r * cos(A);
    double y = r * sin(A);

    printf("Wspolrzedne kartezjanskie wektora: \n");
    printf("x = %.2f \n", x);
    printf("y = %.2f \n", y);

    return 0;
}

double deg2rad(double deg) {
    const double PI = 3.14;
    
    return deg * (PI / 180.0);
}

/*
    r03z04.c: Notacja wykładnicza

    4. Napisz program, który pobiera liczbę zmiennoprzecinkową i wyświetla ją 
    najpierw w postaci ułamka dziesiętnego, a potem w notacji wykładniczej. 
    Zastosuj następujący wzorzec dla danych wyjściowych:

    Podana liczba to 21.290000 lub 2.129000e+001.
*/

#include <stdio.h>

int main(void) {

    float digit = 0.0f;
    
    printf("Podaj dowolna liczbe zmiennoprzecinkowa: ");
    scanf("%f", &digit);

    printf("Podana liczba to %f lub %e \n", digit, digit);

    return 0;
}

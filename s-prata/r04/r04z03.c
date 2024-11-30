/*
    r04z03.c: Formatowanie liczb zmiennoprzecinkowych

    3. Napisz program, który pobiera liczbę zmiennoprzecinkową, a następnie 
    wyświetla ją w postaci:ułamka dziesiętnego i w zapisie wykładniczym. Niech 
    wyświetlany tekst wygląda następująco:
    
    a. Wpisano liczbę 21.3 lub 2.1e+001.
    b. Wpisano liczbę +21.290 lub 2.129E+001.
*/

#include <stdio.h>

int main(void) {

    float digit = 0.0f;
        
    printf("Podaj liczbe zmiennoprzecinkowa: ");
    scanf("%f", &digit);
        
    printf("Wpisano liczbe %.1f lub %.1e \n", digit, digit);
    printf("Wpisano liczbe %+.3f lub %.3E \n", digit, digit);

    return 0;
}

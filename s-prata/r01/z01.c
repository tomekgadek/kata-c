/*
    z01.c: Przeliczanie cali na cm

    1. Zostales walasnie zatrudniony przez firme MacroMuscle, Inc. (oprogramowanie dla kulturystow).
    Zamierz ona wejsc na rynek europejski i potrzebuje programu przeliczajacego cale na centymetry
    (1 cal = 2.54 cm). Program powinien pobierac liczbe cali podana przez uzytkownika. Twoim zadaniem
    jest okreslenie celow i wykonanie peojektu programu (kroki 1 i 2 procesu programowania).
*/

/*
    ## Cel programu.

    Celem programu jest przeliczanie cali na cm (rynek europejski). 

    ## Projekt programu.

    Grupa docelowa programu to kulturysci. Dane I/O powinny byc reprezentowane w postaci
    liczb  zmiennoprzecinkowych. Uzytkownik bedzie mial mozliwosc wprowadzania
    danych w calach, a program powinien zwracac mu juz przeliczona wartosc w centymetrach.
*/

#include <stdio.h>

#define INCH_TO_CM 2.54 // 1cal = 2.54cm

int main(void) {

    float inch = 0.0f;

    printf("Podaj rozmiar bicepsa w calach: ");
    scanf("%f", &inch);
    
    float result_in_cm = inch * INCH_TO_CM;
    
    printf("%.2f cal(e/i) to %.2f cm. \n", inch, result_in_cm);

    return 0;
}

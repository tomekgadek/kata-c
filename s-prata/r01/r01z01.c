/*
    r01z01.c: Przeliczanie cali na cm

    1. Zostałes własnie zatrudniony przez firme MacroMuscle, Inc. (oprogramowanie dla kulturystów).
    Zamierza ona wejść na rynek europejski i potrzebuje programu przeliczającego cale na centymetry
    (1 cal = 2.54 cm). Program powinien pobierać liczbę cali podaną przez użytkownika. Twoim zadaniem
    jest określenie celów i wykonanie projektu programu (kroki 1 i 2 procesu programowania).
*/

/*
    ## Cel programu.

    Celem programu jest przeliczanie cali na cm (rynek europejski). 

    ## Projekt programu.

    Grupa docelowa programu to kulturyści. Dane I/O powinny byc reprezentowane w postaci
    liczb  zmiennoprzecinkowych. Użytkownik bedzie miał możliwosc wprowadzania
    danych w calach, a program powinien zwracac mu już przeliczoną wartość w centymetrach.
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

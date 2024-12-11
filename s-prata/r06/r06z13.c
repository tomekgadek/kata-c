/*
    r06z13.c: Procent prosty i składany

    13. Ewa inwestuje 100 zł z 10% procentem prostym. (Każdego roku liczysz 
    zysk w wysokości 10% jej początkowej wartości.) Kasia inwestuje 100 zł 
    z 5% rocznym procentem składanym (5% jej bieżącej wartości, 
    zwiększając w sobie proporcjonalnie doliczone odsetki). Napisz program, 
    który oblicza, po ilu latach wartość inwestycji Kasi przekroczy wartość 
    inwestycji Ewy, oraz wyświetla te wartości w tym momencie.
*/

#include <stdio.h>

int main(void) {

    double capital = 100.0; // 100 PLN

    // procent prosty
    double eve_percent = 0.1;  // 10%
    double eve_investment = capital;

    // procent skladany
    double kate_percent = 0.05;  // 5%;
    double kate_investment = capital;

    int years_of_investment = 0;

    while(kate_investment <= eve_investment) {

        eve_investment += eve_percent * capital;
        kate_investment += kate_percent * kate_investment;


        years_of_investment++;
    }

    printf("Po %d latach wartosc inwestycji Kasi %.2lf > wartosc inwestycji Ewy %.2lf. \n", 
        years_of_investment, kate_investment, eve_investment);

    return 0;
}

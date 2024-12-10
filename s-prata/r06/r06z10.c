/*
    r06z10.c: Sumy ciągów

    10. Napisz program, który oblicza sumę 1, 2, 3 i tak dalej (aż do 
    pewnej granicy) wyrazów następujących ciągów:

        1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
        1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...

    Maksymalna liczba wyrazów do zsumowania powinna być określana przez 
    użytkownika. Przyjrzyj się sumom dla 20, 100 i 500 wyrazów. Czy któryś 
    z ciągów wydaje się zbiegać do jakiejś wartości?  
    
    Wskazówka:
        -1 pomnożone przez siebie nieparzystą ilość razy jest równe -1, a 
        parzystą ilość razy jest równe +1.
*/

#include <stdio.h>

int main(void) {

    int max_steps = 0;

    printf("Podaj liczbe sumowan: ");
    scanf("%d", &max_steps);

    double numerator = 1.0;
    double denominator = 1.0;

    double series1 = 0.0;
    double series2 = 0.0;

    double change_sign = 1.0;

    while(max_steps-- > 0) {

        series1 += (numerator / denominator);
        series2 += (numerator * change_sign / denominator);
        denominator += 1.0;

        change_sign *= -1.0;
    }

    printf("Suma 1 ciagu wynosi: %.2lf \n", series1);
    printf("Suma 2 ciagu wynosi: %.2lf \n", series2);

    return 0;
}

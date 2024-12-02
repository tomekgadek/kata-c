/*
    r05z03.c: Przelicz dni na tygodnie i dni

    3. Napisz program, który prosi o podanie liczby dni, a następnie 
    zamienia ją na liczbę tygodni i dni. (Np. 18 dni powinno zostać 
    przeliczone na 2 tygodnie i 4 dni.)
*/

const int WEEK = 7;

#include <stdio.h>

int main(void) {

    int days_input = 0;

    printf("Podaj liczbe dni: ");
    scanf("%d", &days_input);

    int weeks = days_input / WEEK;
    int days = days_input % WEEK;
    
    printf("%d dni = %d tyg. i %d dni. \n", days_input, weeks, days);

    return 0;
}

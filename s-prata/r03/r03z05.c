/*
    r03z05.c: Przelicz wiek użytkownika na sekundy

    5. W roku jest około 3.156 × 10⁷ sekund. Napisz program, 
    który pobiera Twój wiek w latach, a następnie przelicza go na sekundy.
*/

#include <stdio.h>

int main(void) {

    double seconds_in_year = 3.156e7;
    double age = 0.0f;

    printf("Podaj wiek: ");
    scanf("%lf", &age);

    double your_age_in_seconds = age * seconds_in_year;

    printf("%.2lf lat = %e sek. \n", age, your_age_in_seconds);

    return 0;
}

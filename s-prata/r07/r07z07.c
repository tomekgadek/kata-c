/*
    r07z07.c: Kalkulator wynagrodzen

    7. Napisz program, który pobiera liczbę przepracowanych godzin w 
    tygodniu, a następnie wyświetla wynagrodzenie brutto, podatek oraz 
    wynagrodzenie netto. Przyjmij następujące wartości:

    a. podstawowe wynagrodzenie = 40 zł / godz.  
    b. nadgodziny (powyżej 40 godzin w tygodniu) = 150% podstawowego 
    wynagrodzenia  
    c. podatek:
        - 15% dla pierwszych 1200 zł
        - 20% dla kolejnych 600 zł
        - 25% dla reszty wynagrodzenia  

    Użyj stałych #define i nie przejmuj się, że przykład nie przystaje do 
    aktualnych przepisów podatkowych.
*/

#include <stdio.h>

#define WEEKLY_WORK_HOURS    40    // Norma godzin pracy w tygodniu

#define BASIC_WAGE           40.0  // Wynagrodzenie podstawowe w zł / godz.
#define OVERTIME_MULTIPLIER  1.5   // Mnożnik dla nadgodzin

#define TAX_THRESHOLD_1      1200  // Pierwszy próg podatkowy (1200 zł)
#define TAX_THRESHOLD_2      600   // Drugi próg podatkowy (600 zł)
#define TAX_RATE_1           0.15  // Podatek dla pierwszych 1200 zł (15%)
#define TAX_RATE_2           0.20  // Podatek dla kolejnych 600 zł (20%)
#define TAX_RATE_3           0.25  // Podatek dla reszty wynagrodzenia (25%)

int main(void) {

    int working_hours = 0;
    double gross_salary = 0.0;
    double net_salary = 0.0;
    double tax = 0.0;

    printf("Podaj liczbe przepracowanych godzin w tygodniu: ");
    scanf("%d", &working_hours);
    
    // stawka podstawowa / wynagrodzenie netto
    if(working_hours > WEEKLY_WORK_HOURS) {

        net_salary = WEEKLY_WORK_HOURS * BASIC_WAGE;
        working_hours -= WEEKLY_WORK_HOURS;
    } else {

        net_salary = working_hours * BASIC_WAGE;
        working_hours = 0.0;
    }

    // stawka za nadgodziny / wynagrodzenie netto
    if(working_hours > 0.0) {
        net_salary += working_hours * BASIC_WAGE * OVERTIME_MULTIPLIER;
    }

    // podatek
    if(net_salary <= TAX_THRESHOLD_1) {

        tax = TAX_RATE_1 * net_salary;
    } else if(net_salary > TAX_THRESHOLD_1 && 
        net_salary <= (TAX_THRESHOLD_1 + TAX_THRESHOLD_2)) {

        tax = TAX_RATE_1 * TAX_THRESHOLD_1;
        tax += TAX_RATE_2 * (net_salary - TAX_THRESHOLD_1);
    } else {

        tax = TAX_RATE_1 * TAX_THRESHOLD_1;
        tax += TAX_RATE_2 * TAX_THRESHOLD_2;
        tax += TAX_RATE_3 * (net_salary - TAX_THRESHOLD_1 - TAX_THRESHOLD_2);
    }

    // wynagrodzenie brutto
    gross_salary = net_salary + tax;

    printf("Wynagrodzenie brutto: %10.2lf \n", gross_salary);
    printf("Podatek:              %10.2lf \n", tax);
    printf("Wynagrodzenie netto:  %10.2lf \n", net_salary);

    return 0;
}

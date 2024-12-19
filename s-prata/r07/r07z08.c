/*
    r07z08.c: Kalkulator wynagrodzen z menu

    8. Zmień założenie a. w ćwiczeniu 6 tak, aby program wyświetlał menu 
    pozwalające wybrać stawkę wynagrodzenia (zastosuj instrukcję switch). 
    Po uruchomieniu program powinien wyświetlać coś w tym rodzaju:

    ***************************************************************************
    Podaj liczbę odpowiadającą zadanej stawce wynagrodzenia lub opcji:
    1) 35 zł/godz.                                  2) 37 zł/godz.
    3) 40 zł/godz.                                  4) 45 zł/godz.
    5) wyjście
    ***************************************************************************

    W przypadku wybrania opcji od 1 do 4, program powinien poprosić o podanie 
    liczby przepracowanych godzin. Po wyświetleniu wyników, program powinien 
    wrócić do menu. W przypadku wpisania wartości innej niż cyfry z przedziału 
    od 1 do 5, program powinien przypomnieć użytkownikowi o dostępnych opcjach, 
    a następnie wrócić do menu. Stawki wynagrodzenia i podatku przedstaw za 
    pomocą stałych #define.
*/

#include <stdio.h>

#define WEEKLY_WORK_HOURS    40    // Norma godzin pracy w tygodniu

#define PAY_RATE_35          35.0  // Wynagrodzenie: 35 zł/godz.
#define PAY_RATE_37          37.0  // Wynagrodzenie: 37 zł/godz.
#define PAY_RATE_40          40.0  // Wynagrodzenie: 40 zł/godz.
#define PAY_RATE_45          45.0  // Wynagrodzenie: 45 zł/godz.

#define OVERTIME_MULTIPLIER  1.5   // Mnożnik dla nadgodzin

#define TAX_THRESHOLD_1      1200  // Pierwszy próg podatkowy (1200 zł)
#define TAX_THRESHOLD_2      600   // Drugi próg podatkowy (600 zł)
#define TAX_RATE_1           0.15  // Podatek dla pierwszych 1200 zł (15%)
#define TAX_RATE_2           0.20  // Podatek dla kolejnych 600 zł (20%)
#define TAX_RATE_3           0.25  // Podatek dla reszty wynagrodzenia (25%)

void menu(void);
void alert(void);

int main(void) {

    int working_hours = 0;
    double gross_salary = 0.0;
    double net_salary = 0.0;
    double tax = 0.0;
    double pay_rate = PAY_RATE_40;

    int option = 0;

    while(option != 5) {
        menu();

        if(scanf("%d", &option) != 1) {
            alert();
            fflush(stdin);
            continue;
        }

        switch (option) {
        case 1:
            pay_rate = PAY_RATE_35;
            break;
        case 2:
            pay_rate = PAY_RATE_37;
            break;
        case 3:
            pay_rate = PAY_RATE_40;
            break;
        case 4:
            pay_rate = PAY_RATE_45;
            break;
        case 5:
            continue;
        }

        // wlasciwe obliczenia
        printf("Podaj liczbe przepracowanych godzin w tygodniu: ");
        scanf("%d", &working_hours);
    
        // stawka podstawowa / wynagrodzenie netto
        if(working_hours > WEEKLY_WORK_HOURS) {

            net_salary = WEEKLY_WORK_HOURS * pay_rate;
            working_hours -= WEEKLY_WORK_HOURS;
        } else {

            net_salary = working_hours * pay_rate;
            working_hours = 0.0;
        }

        // stawka za nadgodziny / wynagrodzenie netto
        if(working_hours > 0.0) {
            net_salary += working_hours * pay_rate * OVERTIME_MULTIPLIER;
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
    }

    printf("Koniec... \n");

    return 0;
}

void menu(void) {

    printf("*************************************************************************** \n");
    printf("Podaj liczbę odpowiadającą zadanej stawce wynagrodzenia lub opcji: \n");
    printf("1) 35 zł/godz.                                  2) 37 zł/godz. \n");
    printf("3) 40 zł/godz.                                  4) 45 zł/godz. \n");
    printf("5) wyjście \n");
    printf("*************************************************************************** \n");
    printf(">> ");
}

void alert(void) {
    printf("!!! Blad\n!!! Obslugiwane opcje: 1 - 5 !!! \n");
}

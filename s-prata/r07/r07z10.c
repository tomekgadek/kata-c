/*
    r07z10.c: Amerykańska skala podatkowa

    10. Amerykańska skala podatkowa z roku 1988 była jedną z najprostszych w 
    ostatnich czasach. Składała się ona z czterech kategorii, z których każda 
    zawierała dwie stawki. Oto jej podsumowanie:

    | Kategoria                       | Podatek                                  |
    |---------------------------------|------------------------------------------|
    | Stan wolny                      | 15% dochodu do 17 850 $ plus 28% reszty  |
    | Głowa rodziny                   | 15% dochodu do 23 900 $ plus 28% reszty  |
    | Małżeństwo, rozliczenie wspólne | 15% dochodu do 29 750 $ plus 28% reszty  |
    | Małżeństwo, rozliczenie osobne  | 15% dochodu do 14 875 $ plus 28% reszty  |

    Przykład: 
    Osoba stanu wolnego, która osiągnęła dochód w wysokości 20 000 dolarów, 
    jest winna państwu: 0.15 x 17 850 $ + 0.28 x (20 000 $ - 17 850 $).  
   
    Napisz program, który pobiera kategorię i dochód podlegający 
    opodatkowaniu, a następnie oblicza wysokość kwoty podatku. Użyj pętli tak, 
    aby użytkownik mógł obliczyć podatek dla kilku różnych przypadków w czasie 
    jednej sesji z programem.
*/

#include <stdio.h>

// kategorie
#define SINGLE                  1
#define HEAD_OF_HOUSEHOLD       2
#define MARRIED_JOINT           3
#define MARRIED_SEPARATE        4

// limity dochodu
#define LIMIT_SINGLE            17850.0
#define LIMIT_HEAD_OF_HOUSEHOLD 23900.0
#define LIMIT_MARRIED_JOINT     29750.0
#define LIMIT_MARRIED_SEPARATE  14875.0

void menu(void);
double calculate_tax(double limit_type, double income);

int main(void) {

    double income = 0.0, tax_amount = 0.0;

    for(int category = 0; ; ) {

        menu();
        if(scanf("%d", &category) != 1) {
            break;
        }

        if(category < 1 || category > 4) {
            break;
        }

        printf("Podaj swoj dochod: ");
        scanf("%lf", &income);

        switch(category) {
        case SINGLE:
            tax_amount = calculate_tax(LIMIT_SINGLE, income);
            break;
        case HEAD_OF_HOUSEHOLD:
            tax_amount = calculate_tax(LIMIT_HEAD_OF_HOUSEHOLD, income);
            break;
        case MARRIED_JOINT:
            tax_amount = calculate_tax(LIMIT_MARRIED_JOINT, income);
            break;
        case MARRIED_SEPARATE:
            tax_amount = calculate_tax(LIMIT_MARRIED_SEPARATE, income);
            break;
        }

        printf("Wysokosc kwoty podatku: %.2lf. \n", tax_amount);
    }

    printf("Koniec. \n");

    return 0;
}

void menu(void) {

    printf("Wybierz kategorie: \n");
    printf("(1) Stan wolny. \n");
    printf("(2) Glowa rodziny. \n");
    printf("(3) Malzenstwo, rozliczenie wspolne. \n");
    printf("(4) Malzenstwo, rozliczenie osobne. \n");
    printf("(*) Zakoncz (dowolny inny znak). \n");
    printf(">> ");
}     

double calculate_tax(double limit_type, double income) {
    const double LOWER_RATE = 0.15;  // 15%
    const double HIGHER_RATE = 0.28; // 28%

    if(income <= limit_type) {
        return LOWER_RATE * income; 
    }

    return (LOWER_RATE * limit_type) + (HIGHER_RATE * (income - limit_type));
}

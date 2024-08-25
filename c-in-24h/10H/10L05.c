/* 10L05.c: Zastosowanie instrukcji switch-break */

#include <stdio.h>

int main(void)
{
    int day;
    
    printf("Wpisz 1 cyfre - numer dnia w tygodniu \n");
    printf("(w zakresie od 1 do 7):\n");
    
    day = getchar();
    switch(day) {
        case'1':
            printf("Dzien 1 - Niedziela.\n");
            break;  
        case'2':
            printf("Dzien 2 - Poniedzialek.\n");
            break;
        case'3':
            printf("Dzien 3 - Wtorek.\n");
            break;
        case'4':
            printf("Dzien 4 - Sroda.\n");
            break;
        case'5':
            printf("Dzien 5 - Czwartek.\n");
            break;
        case'6':
            printf("Dzien 6 - Piatek.\n");
            break;
        case'7':
            printf("Dzien 7 - Sobota.\n");
            break;
        default:
            printf("Cyfra spoza zakresu od 1 do 7.\n");
            break;
    }

    return 0;
}

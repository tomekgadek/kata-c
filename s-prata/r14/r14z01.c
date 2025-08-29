/*
    r14z01.c: Suma dni w roku do wybranego miesiąca (wersja z nazwą miesiąca)

    1. Ponownie wykonaj funkcję z pytania nr 5, ale tym razem niech jej 
    argument będzie nazwą, a nie numerem miesiąca. (Pamiętaj o funkcji 
    strcmp().)

    Zagadnienia wymagane do zrozumienia tego zadania:

    + Zaprojektuj szablon struktury, przechowujący nazwę 
      miesiąca, trzyliterowy skrót nazwy, liczbę dni w miesiącu oraz 
      numer miesiąca.
    + Zdefiniuj tablicę 12 struktur (takich jak w pytaniu nr 3) i zainicjalizuj 
      ją, przyjmując, że rok nie jest przestępny.
    + Napisz funkcję, która po przekazaniu jej numeru miesiąca zwraca całkowitą 
      liczbę dni w roku do tego miesiąca włącznie. Przyjmij, że szablon 
      struktury z pytania nr 3 i tablica struktur z pytania nr 4 są 
      zadeklarowane w innym pliku (to jest pytanie nr 5).
*/

#include <stdio.h>
#include <string.h>

const int NUMBER_OF_MONTHS = 12;
const int NAME_SIZE = 20;
const int SHORT_NAME_SIZE = 4;

struct month {
    char name[NAME_SIZE];
    char short_name[SHORT_NAME_SIZE];
    int days;
    int idx;
};

struct month months[NUMBER_OF_MONTHS] = {
    { "Styczen" , "sty" , 31 , 1 },
    { "Luty" , "lut" , 28 , 2 },
    { "Marzec" , "mar" , 31 , 3 },
    { "Kwiecien" , "kwi" , 30 , 4 },
    { "Maj" , "maj" , 31 , 5 },
    { "Czerwiec" , "cze" , 30 , 6 },
    { "Lipiec" , "lip" , 31 , 7 },
    { "Sierpien" , "sie" , 31 , 8 },
    { "Wrzesien" , "wrz" , 30 , 9 },
    { "Pazdziernik" , "paz" , 31 , 10 },
    { "Listopad" , "lis" , 30 , 11 },
    { "Grudzien" , "gru" , 31 , 12 }
};

int days_including_month(char *, struct month *p_month, int last_idx);

int main(void) {

    printf("Podaj nazwe mesiaca: ");

    char month_name[NAME_SIZE];
    scanf("%s", &month_name[0]);

    int result = days_including_month(&month_name[0], &months[0], NUMBER_OF_MONTHS);
    printf("Suma dni do wybranego miesiaca: %d. \n", result);

    return 0;
}

int days_including_month(char *month_name, struct month *p_month, int last_idx) {

    int sum_days = p_month->days;

    while(strcmp(month_name, p_month->name) != 0) {
        sum_days += p_month->days;

        if(p_month->idx == last_idx) {
            fprintf(stderr, "Nie ma takiego miesiaca: %s\n", month_name);
            return 0;
        }

        p_month++;
    }
    
    return sum_days;
}
/*
    r14z02.c: Suma dni w wybranym dniu, miesiącu i roku
    
    2. Napisz program, który prosi użytkownika o podanie dnia, miesiąca oraz 
    roku. Miesiąc może zostać wskazany za pomocą numeru (np. "9"), nazwy 
    ("wrzesien") lub nazwy skróconej ("wrz"). Program powinien wyświetlić 
    całkowitą liczbę dni w roku do podanego dnia włącznie.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int NUMBER_OF_MONTHS = 12;
const int NAME_SIZE = 20;
const int SHORT_NAME_SIZE = 4;

struct month {
    char name[NAME_SIZE];
    char short_name[SHORT_NAME_SIZE];
    int days;
    int idx;
};

struct date {
    unsigned day;
    char month_name[NAME_SIZE];
    unsigned year;
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

int days_including_date(struct date *p_date, struct month *p_month, int last_idx);
bool is_leap_year(unsigned year);

int main(void) {

    struct date input_date;

    printf("Podaj date, np: [15 paz 2024]: ");
    scanf("%d %s %d", &input_date.day, &input_date.month_name[0], &input_date.year);

    int result = days_including_date(&input_date, &months[0], NUMBER_OF_MONTHS);
    printf("Suma dni do daty w podanym roku: %d. \n", result);

    return 0;
}

int days_including_date(struct date *p_date, struct month *p_month, int last_idx) {

    if(is_leap_year(p_date->year)) {
        (p_month + 1)->days = 29;
    } else {
        (p_month + 1)->days = 28;
    }

    int sum_days = 0;

    while(strcmp(p_date->month_name, p_month->name) != 0 && strcmp(p_date->month_name, p_month->short_name) != 0) {
        sum_days += p_month->days;

        if(p_month->idx == last_idx) {
            fprintf(stderr, "Nie ma takiego miesiaca: %s\n", p_date->month_name);
            return 0;
        }

        p_month++;
    }

    if(p_date->day < 1 || p_date->day > p_month->days) {
        fprintf(stderr, "Nie ma takiego dnia: %d w miesiacu: %s\n", p_date->day, p_month->name);
        return 0;
    }

    sum_days += p_date->day;

    return sum_days;
}

bool is_leap_year(unsigned year) {

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    
    return false;
}

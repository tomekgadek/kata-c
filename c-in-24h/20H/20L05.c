/* 20L05.c: Zastosowanie unii */

#include <stdio.h>
#include <string.h>

struct survey {

    char name[20];
    char c_d_p;
    int age;
    int hour_per_week;

    union {                     /* unia - poczatek deklaracji */
        char cable_company[16]; /* TV kablowa - nazwa */
        char dish_company[16];  /* TV sat - nazwa */
    } provider;                 /* provider - dostawca uslugi */
};

void dataEnter(struct survey *ptr);
void dataDisplay(struct survey *ptr);

int main(void) {

    struct survey tv;
    dataEnter(&tv);
    dataDisplay(&tv);

    return 0;
}

/* definicja funkcji */
void dataEnter(struct survey *ptr) {

    char is_yes[4];

    printf("Czy korzystasz w domu z TV kablowej? (Tak lub NIE) \n");
    gets(is_yes);
    if(is_yes[0] == 'T' || is_yes[0] == 't') {

        printf("Wpisz nazwe firmy - dostawcy TV kablowej:\n");
        gets(ptr->provider.cable_company);
        ptr->c_d_p = 'c';
    } else {

        printf("Czy korzystasz w domu z TV sat? (Tak lub NIE)\n");
        gets(is_yes);
        if(is_yes[0]=='T' || is_yes[0] == 't') {
            printf("Wpisz nazwe firmy - dostawcy TV sat:\n");
            gets(ptr->provider.dish_company);
            ptr->c_d_p = 'd';
        } else {
            ptr->c_d_p = 'p';
        }
    }

    printf("Wpisz swoje nazwisko:\n");
    gets(ptr->name);
    printf("i swoj wiek: \n");
    scanf("%d", &ptr->age);
    printf("Ile godzin tygodniowo ogladasz TV? \n");
    scanf("%d", &ptr->hour_per_week);
}

/* definicja funkcji */
void dataDisplay(struct survey *ptr) {

    printf("Oto dane ktore wprowadziles: \n");
    printf("Nazwisko: %s \n", ptr->name);
    printf("Wiek: %d\n",ptr->age);
    printf("Godzin tygodniowo: %d\n", ptr->hour_per_week);
    if(ptr->c_d_p == 'c')
        printf("Twoja firma TV kablowej: %s \n", ptr->provider.cable_company);
    else if(ptr->c_d_p == 'd')
        printf("Twoja firma TV sat: %s \n", ptr->provider.dish_company);
    else
        printf("Nie korzystasz ani z TV kablowej ani z TV sat. \n");
    
    printf("\nDziekujemy. Koniec ankiety!\n");
}

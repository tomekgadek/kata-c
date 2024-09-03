/* 20L06.c: Definiowanie pol bitowych */

#include <stdio.h>
#include <string.h>

struct bit_field {

    int cable: 1;
    int dish: 1;
};

struct survey {

    char name[20];
    struct bit_field c_d;
    int age;
    int hour_per_week;

    union {
        char cable_company[16];
        char dish_company[16];
    } provider;
};

void dataEnter(struct survey *ptr);
void dataDisplay(struct survey *ptr);

int main(void) {

    struct survey tv;

    dataEnter(&tv);
    dataDisplay(&tv);

    return 0;
}

void dataEnter(struct survey *ptr) {

    char is_yes[4];

    printf("Czy korzystasz w domu z TV kablowej? (Tak lub NIE) \n");
    gets(is_yes);
    if(is_yes[0] == 'T' || is_yes[0] == 't') {

        printf("Wpisz nazwe firmy - dostawcy TV kablowej: \n");
        gets(ptr->provider.cable_company);
        ptr->c_d.cable = 1;
        ptr->c_d.dish = 0;
    } else {

        printf("Czy korzystasz w domu z TV sat? (Tak lub NIE) \n");
        gets(is_yes);
        if((is_yes[0]=='T')||(is_yes[0]=='t')) {

            printf("Wpisz nazwe firmy - dostawcy TV sat: \n");
            gets(ptr->provider.dish_company);
            ptr->c_d.cable = 0;
            ptr->c_d.dish = 1;
        } else {

            ptr->c_d.cable = 0;
            ptr->c_d.dish = 0;
        }
    }

    printf("Wpisz swoje nazwisko:\n");
    gets(ptr->name);
    printf("i swoj wiek: \n");
    scanf("%d", &ptr->age);
    printf("Ile godzin tygodniowo ogladasz TV? \n");
    scanf("%d", &ptr->hour_per_week);
}

void dataDisplay(struct survey *ptr) {

    printf("Oto dane ktore wprowadziles: \n");
    printf("Nazwisko: %s\n", ptr->name);
    printf("Wiek: %d\n", ptr->age);
    printf("Godzin tygodniowo: %d\n", ptr->hour_per_week);
    if(!ptr->c_d.dish && ptr->c_d.cable)
        printf("Twoja firma TV kablowej: %s\n", ptr->provider.cable_company);
    else if(!ptr->c_d.cable && ptr->c_d.dish)
        printf("Twoja firma TV sat: %s\n",ptr->provider.dish_company);
    else
        printf("Nie korzystasz ani z TV kablowej ani z TV sa. \n");

    printf("\nDziekujemy. Koniec ankiety! \n");
}

/* 19L06.c: Zastosowanie zagniezdzonych struktur */

#include <stdio.h>

struct dzial {

    int kod;
    char nazwa[32];
    char stanowisko[16];
};

typedef struct dzial DPT;

struct pracownik {

    DPT d; /*Zagniezdzona struktura*/
    int id;
    char name[32];
};

typedef struct pracownik EMPLY;

/* deklaracje funkcji */
void infoDisplay(EMPLY *ptr);
void infoEnter(EMPLY *ptr);

int main(void) {

    EMPLY info = {
        { 
            01, 
            "Marketing", 
            "Manager" 
        }, 
        0001, 
        "B.Smith"
    };

    printf("Przyklad:\n");
    infoDisplay(&info);

    infoEnter(&info);

    printf("\nOto dane, ktore wprowadziles: \n");
    infoDisplay(&info);

    return 0;
}

void infoDisplay(EMPLY *ptr) {

    printf("Nazwisko: %s \n", ptr->name);
    printf("Numer: %04d \n", ptr->id);
    printf("Nazwa dzialu: %s \n", ptr->d.nazwa);
    printf("Numer dzialu: %02d \n", ptr->d.kod);
    printf("Twoje stanowisko: %s \n", ptr->d.stanowisko);
}

void infoEnter(EMPLY *ptr) {

    printf("\nWpisz swoje dane: \n");
    printf("Nazwisko: \n");
    gets((*ptr).name);
    printf("Funkcja: \n");
    gets((*ptr).d.stanowisko);
    printf("Nazwa dzialu: \n");
    gets((*ptr).d.nazwa);
    printf("Numer dzialu: \n");
    scanf("%d", &(ptr->d.kod));
    printf("Twoj numer ID #: \n");
    scanf("%d",&(ptr->id));
}

/* 19L04.c: Wskaznik do struktury */

#include <stdio.h>

struct komputer {

    float cost;
    int year;
    int cpu_speed;
    char cpu_type[16];
};

typedef struct komputer SC;

/* deklaracja funkcji, nie zwraca wartosci */
void dataReceive(SC *ptr_s);

int main(void) {

    SC model;

    dataReceive(&model);

    printf("Oto dane ktore wprowadziles: \n");
    printf("Rok: %d \n", model.year);
    printf("Koszt: %6.2f zl \n", model.cost);
    printf("CPU typ: %s \n", model.cpu_type);
    printf("Szybkosc CPU: %d MHz \n", model.cpu_speed);

    return 0;
}

void dataReceive(SC *ptr_s) {

    printf("Podaj typ mikroprocesora(CPU): \n");
    gets((*ptr_s).cpu_type);
    printf("Podaj szybkosc CPU w [MHz]: \n");
    scanf("%d", &(ptr_s->cpu_speed)); /* mozna uzyc operatora "->" */
    printf("Podaj rok produkcji: \n");
    scanf("%d", &(*ptr_s).year);
    printf("Za ile go kupiles: \n");
    scanf("%f", &(*ptr_s).cost);
}

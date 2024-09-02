/* 19L03.c: Przekazanie struktury jako argumentu funkcji */

#include <stdio.h>

struct komputer {
    float cost;
    int year;
    int cpu_speed;
    char cpu_type[16];
};

/* synonim dla "struct computer" */
typedef struct komputer SC;

/* deklaracja funkcji */
SC dataReceive(SC s);

int main(void) {

    SC model;

    /* wywolanie funkcji */
    model = dataReceive(model);

    printf("Oto dane ktore wpisales: \n");
    printf("Rok: %d \n", model.year);
    printf("Koszt: %6.2f zl \n", model.cost);
    printf("CPU typ: %s \n", model.cpu_type);
    printf("Szybkosc CPU: %d MHz \n", model.cpu_speed);

    return 0;
}

SC dataReceive(SC s) {

    printf("Podaj typ mikroprocesora(CPU): \n");
    gets(s.cpu_type);
    printf("Podaj szybkosc CPU w [MHz]: \n");
    scanf("%d", &s.cpu_speed);
    printf("Podaj rok produkcji: \n");
    scanf("%d", &s.year);
    printf("Za ile go kupiles: \n");
    scanf("%f", &s.cost);

    return s;
}

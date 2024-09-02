/* 19L01.c: Odwolywanie sie do pol struktury */

#include <stdio.h>

int main(void) {

    struct komputer {
        float cost;
        int year;
        int cpu_speed;
        char cpu_type[16];
    } model;

    printf("Podaj typ mikroprocesora(CPU): \n");
    gets(model.cpu_type);
    printf("Podaj szybkosc CPU w [MHz]: \n");
    scanf("%d", &model.cpu_speed);
    printf("Podaj rok produkcji: \n");
    scanf("%d", &model.year);
    printf("Za ile go kupiles: \n");
    scanf("%f", &model.cost);

    printf("Oto dane ktore wpisales: \n");
    printf("Rok: %d \n", model.year);
    printf("Koszt: %6.2f zl \n", model.cost);
    printf("CPU typ: %s \n", model.cpu_type);
    printf("Szybkosc CPU: %d MHz \n", model.cpu_speed);

    return 0;
}

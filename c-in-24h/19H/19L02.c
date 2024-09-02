/* 19L02.c: Inicjowanie pol struktury */

#include <stdio.h>

int main(void) {

    struct pracownik {
        int Nr;
        char Nazwisko[32];
    };

    struct pracownik info = { 0001, "B.Smith" };

    printf("Wydruk danych z pol struktury! \n");
    printf("Nazwisko pracownika: %s \n", info.Nazwisko);
    printf("Numer-ID #: %04d\n", info.Nr);

    printf("Podaj swoje nazwisko: \n");
    gets(info.Nazwisko);
    printf("Podaj swoj numer: \n");
    scanf("%d", &info.Nr);

    printf("Wpisales swoje dane: \n");
    printf("Name: %s \n", info.Nazwisko);
    printf("Twoj numer identyfikacyjny ID #: %04d \n", info.Nr);

    return 0;
}

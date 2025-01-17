/*
    r11z12.c: Praca z argumentami wiersza poleceń

    12. Napisz program, który wyświetla na ekranie argumenty wiersza poleceń
    w odwrotnej kolejności. Na przykład, jeśli argumentami są słowa
    "idz do domu", program powinien wyswietlic "domu do idz".
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

    printf("Uruchominono program %s. \n", argv[0]);
    printf("Lista argumentow wiersza polecen: \n");

    for(int i = argc - 1; i > 0; --i) {
        printf("%s ", argv[i]);
    }

    printf("\n");

    return 0;
}

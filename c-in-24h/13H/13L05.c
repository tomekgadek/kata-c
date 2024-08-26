/* 13L05.c: Zastosowanie funkcji scanf() */

#include <stdio.h>

int main(void) {

    char str[80];
    int x, y;
    float z;

    printf("Po wpisaniu danych dowolnego typu nacisnij [Enter]:\n");
    printf("Wpisz dwie liczby calkowite:\n");
    scanf("%d %d",&x, &y);
    printf("Wpisz liczbe zmiennoprzecinkowa:\n");
    scanf("%f", &z);
    printf("Wpisz lancuch znakow:\n");
    scanf("%s", str);
    printf("Wpisales nastepujace dane:\n");

    printf("%d %d\n%f\n%s\n", x, y, z, str);

    return 0;
}

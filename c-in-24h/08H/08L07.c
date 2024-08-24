/* Zastosowanie operatora warunkowego ? : */

#include <stdio.h>

int main(void) {

    int x;
    
    x = sizeof(int);

    printf("%s\n", (x == 2) ? "Typ danych int ma 2 bajty" : "Typ danych int nie ma 2 bajtow");
    printf("Maksymalny rozmiar liczby typu int to: %d\n", (x != 2) ? ~(1 << (x * 8 - 1)) : ~(1 << 15));

    return 0;
}

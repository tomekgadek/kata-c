/* 05L01.c: Wczytanie znaku z wejscia poprzez wywolanie funkcji getc() */

#include <stdio.h>

int main(void) {

    int ch;

    printf("Prosze nacisnac klawisz, wpisac pojedynczy znak: \n");
    ch = getc(stdin);
    printf("Wpisales znak %c \n",ch);

    return 0;
}

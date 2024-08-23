/* 05L02.c: Wczytywanie znaku przez funkcje getchar(); */

#include <stdio.h>

int main(void) {

    int ch1, ch2;

    printf("Nacisnij dwa klawisze kolejno:\n");

    ch1 = getc(stdin);
    ch2 = getchar();

    printf("Pirwszy klawisz to bylo: %c\n",ch1);
    printf("Drugi klawisz to bylo: %c\n",ch2);

    return 0;
}

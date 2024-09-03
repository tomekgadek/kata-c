/* 20L04.c: Odwolanie do tej samej pamieci na rozne sposoby */

#include <stdio.h>

union u {
    char ch[4]; /* cztery znaki = 4 bajty */
    int num;    /* (lub) jedna liczba 4 bajty */
};

/* deklaracja funkcji inicjujacej unie */
int unionInitialize(union u val);

int main(void) {

    union u val; /* deklaracja unii typu "u" (zmiennej): val */
    int x;

    x = unionInitialize(val); /* wywolanie funkcji */

    printf("Dwie stale znakowe zawarte w unii: \n");
    printf("%c \n", x & 0x00FF);//Wyswietlany jest najpierw mlodszy bajt='H';
    printf("%c \n", x >> 8);
    printf("%c \n", x >> 16);
    printf("%c \n", x >> 24);

    return 0;
}

int unionInitialize(union u val) {
    val.ch[0] = 'K';
    val.ch[1] = 'a';
    val.ch[2] = 't';
    val.ch[3] = 'e';

    return val.num;
}

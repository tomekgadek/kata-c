/* 07L04c.c: Warunek przerwania pÍtli for */

#include <stdio.h>

int main(void) {

    int c;

    printf("Wpisz znak: (znak x = koniec)\n");
    for(c = ' '; c != 'x'; ) {
    
        c = getc(stdin);
        putc(c, stdout);
    }

    printf("\nJestem poza petla. Koniec.\n");    

    return 0;
}

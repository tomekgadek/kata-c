/* 07L01.c: Zastosowanie petli typu while */

#include <stdio.h>

int main(void) {

    int c;
    
    c=' ';
    printf("Wpisz znak: (znak x = koniec)\n");
    while(c != 'x') {
    
        c = getc(stdin);
        putchar(c);
    }
    printf("\nJestem poza petla. Koniec.\n");    

    return 0;
}

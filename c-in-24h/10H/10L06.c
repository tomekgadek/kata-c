/* 10L06.c: Przerwanie nieskonczonej petli */

#include <stdio.h>

int main(void) {

    int c;
    
    printf("Wpisz znak:\n('x' + [ENTER] = Koniec)\n");
    while(1) {
    
        c = getc(stdin);

        if(c == 'x')
            break;
    }
    printf("Petla zostala przerwana. Koniec!\n");

    return 0;
}

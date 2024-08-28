/* 07L02.c: Zastosowanie petli do-while */

#include <stdio.h>

int main(void) {

    int i;
    
    i = 65;
    do {
        printf("Wartosc numeryczna znaku %c wynosi %d\n", i, i);
        i++;
    } while(i < 72);

    return 0;
}

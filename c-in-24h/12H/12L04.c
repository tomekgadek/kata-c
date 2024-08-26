/* 12L04.c: Wydruk elementow tablicy znakowej */

#include <stdio.h>

int main(void) {

    char array_ch[7] = { 'H', 'e', 'l', 'l', 'o', '!' , '\0' };
    int i;
    
    for(i = 0; i < 7; i++)
        printf("array_ch[%d] zawiera: %c \n", i, array_ch[i]);
    
    /* --- metoda I --- */
    printf("Wszystkie elementy razem(Metoda I): \n");
    
    for(i = 0; i < 7; i++)
        printf("%c", array_ch[i]);
    
    /* --- metoda II --- */
    printf("\nWszystkie elementy razem(Metoda II): \n");
    printf("%s \n", array_ch);

    return 0;
}

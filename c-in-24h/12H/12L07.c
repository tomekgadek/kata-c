/* 12L07.c: Inicjowanie tablic bezwymiarowych */

#include <stdio.h>

int main(void) {
    
    char array_ch[] = { 
        'C', ' ',
        'i', 's', ' ',
        'p', 'o', 'w', 'e', 'r', 'f', 'u', 'l', '!', '\0'
    };
    
    int list_int[][3] = {
        1, 1, 1,
        2, 2, 8,
        3, 9, 27,
        4, 16, 64,
        5, 25, 125,
        6, 36, 216,
        7, 49, 343
    };
    
    printf("Rozmiar tablicy array_ch[] wynosi %lu-bajtow. \n", sizeof(array_ch));
    printf("Rozmiar tablicy list_int[][3] wynosi %lu-bajty. \n", sizeof(list_int));

    return 0;
}

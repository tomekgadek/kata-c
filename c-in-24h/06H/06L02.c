/* 06L02.c: Operatory pre- oraz post-inkrementacji (dekrementacji) */

#include <stdio.h>

int main(void) {
   
    int w, x, y, z, wynik;
    
    w = x = y = z = 1; /* inicjalizacja zmiennych w, x, y, z */

    printf("Dane w = %d, x = %d, y = %d, z = %d,\n", w, x, y, z);

    wynik = ++w;
    printf("++w wynosi: %d\n", wynik);
    wynik = x++;
    printf("x++ wynosi: %d\n",wynik);
    wynik = --y;
    printf("--y wynosi: %d\n",wynik);
    wynik = z--;
    printf("z-- wynosi: %d\n",wynik);

    return 0;
}

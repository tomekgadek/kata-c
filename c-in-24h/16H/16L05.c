/* 16L05.c: Przekazywanie wskaznikow do funkcji */

#include <stdio.h>

void chPrint(char *ch); /* deklaracja funkcji */
int dataAdd(int *list,int max); /* deklaracja funkcji */

int main(void) {

    char str[] = "It's a string!";
    char *ptr_str;
    int list[5] = { 1, 2, 3, 4, 5 };
    int *ptr_int;

    /* zainicjowanie wskaznika do tablicy */
    ptr_str = str;
    chPrint(ptr_str);   /* wywolanie funkcji chPrint ze wskaznikiem */
    chPrint(str);       /* wywolanie funkcji z tablica jako argument */

    /* wskaznikowi przypisujemy adres startowy tablicy */
    ptr_int = list;
    printf("Suma zwrocona przez funkcje dataAdd(): %d\n", dataAdd(ptr_int, 5));
    printf("Suma zwrocona przez funkcje dataAdd(): %d\n", dataAdd(list, 5));

    return 0;
}

void chPrint(char *ch) { /* definicja funkcji */
    printf("%s\n",ch);
}
int dataAdd(int *list,int max) { /* definicja funkcji */

    int i;
    int sum = 0;

    for(i = 0; i < max; i++)
        sum += list[i];
    
    return sum;
}

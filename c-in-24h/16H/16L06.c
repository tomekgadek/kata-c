/* 16L06.c: Przekazywanie listlic wielowymiarowych */

#include <stdio.h>

/* deklaracje funkcji */
int dataAdd1(int list[][5], int max1, int max2);
int dataAdd2(int *list, int max1, int max2);

/* funkcja main() */
int main(void) {

    int list[2][5] = {
        1, 2, 3, 4, 5,
        5, 4, 3, 2, 1
    };

    int *ptr_int;

    printf("Suma zwrocona przez dataAdd1(): %d\n", dataAdd1(list, 2, 5));
    ptr_int = &list[0][0];
    printf("Suma zwrocona przez dataAdd2(): %d\n", dataAdd2(ptr_int, 2, 5));

    return 0;
}

/* definicja funkcji 1 */
int dataAdd1(int list[][5],int max1,int max2) {

    int i, j;
    int suma = 0;

    for(i = 0; i < max1; i++)
        for(j = 0; j < max2; j++)
            suma += list[i][j];
    
    return suma;
}

/* definicja funkcji 2 */
int dataAdd2(int *list, int max1, int max2) {

    int i, j;
    int suma = 0;

    for(i = 0; i < max1; i++)
        for(j = 0; j < max2; j++)
            suma += *(list + (i * max2 + j));

    return suma;
}

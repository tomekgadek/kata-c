/* 23L01.c: Uzycie dyrektywy #define */

#include <stdio.h>

#define METHOD "ABS"
#define ABS(val) ((val) < 0 ? -(val) : (val))
#define MAX_LEN 8
#define NEGATIVE_NUM -10

int main(void) {

    char *str = METHOD;
    int array[MAX_LEN];
    int i;

    printf("Zawartosc tablicy przed makrem ABS: \n");
    for(i = 0; i < MAX_LEN; i++) {

        array[i] = (i + 1) * NEGATIVE_NUM;
        printf("array[%d]: %d \n", i, array[i]);
    }
    
    printf("Po zastosowaniu makra: %s \n", str);
    for(i = 0; i < MAX_LEN; i++) {
        printf("ABS(%d): %3d \n", array[i], ABS(array[i]));
    }

    return 0;
}

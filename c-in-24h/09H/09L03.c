/* 09L03.c: Uzycie specyfikatorow %hd, %ld oraz %lu */

#include <stdio.h>

int main(void) {

    short int x = 0xFFFF;
    unsigned int y = 0xFFFFU;
    long int s = 0xFFFFFFFFl;
    unsigned long int t = 0xFFFFFFFFL;

    printf("The short int of 0xFFFF is %hd\n", x); 
    printf("The unsigned int of 0xFFFF is %u\n", y);
    printf("The long int of 0xFFFFFFFF is %ld\n", s);
    printf("The unsigned long int of 0xFFFFFFFF is %lu\n", t);

    return 0;
}    

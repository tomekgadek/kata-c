/* 07L06.c: Petle zagniezdzone */

#include <stdio.h>

int main(void) {
   
    int i,j;
    
    for(i=1;i<=3;i++) { /* Petla zewnetrzna */
        printf("Start petli zewnetrznej. Numer petli Z%d\n", i);
        for(j = 1; j <= 4; j++) { /* Petla wewnetrzna */
            printf("Cykl Nr %d petli wewnetrznej.\n", j);
        }
        printf("  Koniec petli zewnetrznej. Nr Z%d\n", i);
    }

    return 0;
}

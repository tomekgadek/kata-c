/* 10L02.c: Zastosowanie if-else */

#include <stdio.h>

int main(void) {

    int i;
    
    printf("Liczby parzyste:   Liczby nieparzyste:\n");
    for(i = 0; i < 10; i++) {
        if(i % 2 == 0) {
            printf("%10d", i);
        } else {
            printf("%20d\n", i);
        }
    }

    return 0;
}

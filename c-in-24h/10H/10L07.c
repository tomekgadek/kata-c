/* 10L07.c: Zastosowanie instrukcji continue */

#include <stdio.h>

int main(void) {

    int i, sum;
    
    sum = 0;
    for(i = 1; i < 8; i++) {
    
        if((i==3) || (i==5))
            continue;
        sum += i;
    }
    printf("Suma liczb: 1, 2, 4, 6 oraz 7 wynosi: %d\n", sum);    

    return 0;
}

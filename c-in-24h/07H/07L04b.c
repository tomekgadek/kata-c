/* 07L04b.c: Wiele wyrazen w naglowku petli for - przyklad 2 */

#include <stdio.h>

int main(void) {
   
    int i, j;
    
    for(i = 0, j = 1; i < 8; i++, j++) {
        printf("%d - %d = %d\n", j, i, j-i);
    }

    return 0;
}

/* 17L03.c: Zastosowanie funkcji calloc() */

#include <stdio.h>
#include <stdlib.h>

/* funkcja main() */
int main(void) {

    float *ptr1, *ptr2;
    int i, n;
    int termination = 1;
    puts("Zastosowanie funkcji malloc() - ptr2, calloc() - ptr1:");
    n = 5;
    ptr2 = malloc(n * sizeof(float));
    ptr1 = calloc(n, sizeof(float));

    if(ptr1==NULL) {

        printf("malloc() zwrocila pusty wskaznik.\n");
    } else if(ptr2 == NULL) {

        printf("calloc() zwrocila pusty wskaznik.\n");
    } else {
        for(i = 0; i < n; i++)
            printf("ptr1[%d] = %5.2f, ptr2[%d] = %5.2f\n", i, *(ptr1 + i), i, *(ptr2 + i));
        free(ptr1);
        free(ptr2);
        termination = 0;
    }

    return termination;
}

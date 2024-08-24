/* 09L04.c: Zastosowanie funkcji: sin(); cos(); tan() */

#include <stdio.h>
#include <math.h>

#define PI 3.141593

int main(void) {

    double x = 45.0; /* kat x = 45 stopni */
    x *= PI / 180.0; /* zamiana stopni na radiany */

    printf("Sinus 45 st: %f\n", sin(x));
    printf("Kosinus 45 st: %f\n", cos(x));
    printf("Tangens 45 st: %f\n", tan(x));

    return 0;
}    
   
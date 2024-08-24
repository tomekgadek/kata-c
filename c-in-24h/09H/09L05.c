/* 09L05.c: Uzycie funkcji pow() i sqrt() */

#include <stdio.h>
#include <math.h>

int main(void) {

    double x, y, z;

    x = 64.0;
    y = 3.0;
    z = 0.5;

    printf("The 64 x 64 x 64 is: %7.0f\n", pow(x, y));
    printf("The square root of 64 is: %2.0f\n", sqrt(x));
    printf("pow(64.0, 0,5) return: %2.0f\n",pow(x, z));

    return 0;
}    

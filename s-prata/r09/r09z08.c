/*
    r09z08.c: Systemy liczbowe

    8. Uogólnij funkcję 'do_binar' z listingu 9.9 tak, aby pobierała ona drugi 
    argument z przedziału 2–10, a następnie wyświetlała pierwszy argument w 
    systemie liczbowym określonym przez drugi argument. Na przykład, 
    wywołanie 'do_binar(209, 4)' powinno wyświetlić liczbę 209 w systemie 
    czwórkowym.
*/

#include <stdio.h>
#include <stdlib.h>

void do_binar(int, int);

int main(void) {

    do_binar(209, 2); printf("\n");  // 11010001
    do_binar(209, 3); printf("\n");  // 21202
    do_binar(209, 4); printf("\n");  // 3101
    do_binar(209, 5); printf("\n");  // 1314
    do_binar(209, 6); printf("\n");  // 545
    do_binar(209, 7); printf("\n");  // 416
    do_binar(209, 8); printf("\n");  // 321
    do_binar(209, 9); printf("\n");  // 252
    do_binar(209, 10); printf("\n"); // 209

    return 0;
}

void do_binar(int digit, int number_system) {

    if(number_system < 2 || number_system > 10) {
        fprintf(stderr, "!!! Incorrect number system !!!");
        exit(1);
    }
    
    int r = digit % number_system;
    if(digit >= number_system) {
        do_binar(digit / number_system, number_system);
    }

    printf("%d", r);
}

/* 05L08.c: Zastosowanie specyfikatora precyzji */

#include <stdio.h>

int main(void) {

    int int_num;
    double flt_num;

    int_num = 123;
    flt_num = 123.456789;
    
    printf("Domyslny format calkowity :             %d\n", int_num);
    printf("Ze specyfikatorem precyzji:             %2.8d\n", int_num);
    printf("Domyslny format zmiennoprzecinkowy :    %f\n", flt_num);
    printf("Ze specyfikatorem precyzji:             %-10.2f\n", flt_num);

    return 0;
}

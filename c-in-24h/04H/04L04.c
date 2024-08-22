/* 04L04.c Operacje zmiennoprzecinkowe */

#include <stdio.h>

int main(void) {

    int int_num1, int_num2, int_num3; /* Deklaracja zmiennych calkowitych */
    float flt_num1, flt_num2, flt_num3; /* Deklaracja zmiennych zmiennoprzecinkowych */
    
    int_num1 = 32 / 10; /* Dzielna i dzielnik calkowite */
    flt_num1 = 32 / 10;
    int_num2 = 32.0 / 10; /* Dzielnik calkowity */
    flt_num2 = 32.0 / 10;
    int_num3 = 32 / 10.0; /* Dzielna calkowita */
    flt_num3 = 32 / 10.0;

    printf("Dzielenie calkowite 32/10 wynik: %d\n", int_num1);
    printf("Dzielenie zmiennoprzecinkowe 32/10 wynik: %f\n", flt_num1);
    printf("Dzielenie calkowite 32.0/10 wynik: %d\n", int_num2);
    printf("Dzielenie zmiennoprzecinkowe 32.0/10 wynik: %f\n", flt_num2);
    printf("Dzielenie calkowite 32/10.0 wynik: %d\n",  int_num3);
    printf("Dzielenie zmiennoprzecinkowe 32/10.0 wynik: %f\n", flt_num3);

    return 0;
}

/* 08L01.c: Zastosowanie operatora sizeof */

#include <stdio.h>

int main(void) {

    char ch = ' ';
    int int_num = 0;
    float flt_num = 0.0f;
    double dbl_num = 0.0;
       
    printf("Dane typu char zajmuja: %lu-bajt\n", sizeof(char));
    printf("Zmienna ch zajmuje: %lu-bajt\n", sizeof ch);
    printf("Dane typu int zajmuja: %lu-bajty\n", sizeof(int));
    printf("Zmienna int_num zajmuje: %lu-bajty\n", sizeof int_num);
    printf("Dane typu float zajmuja: %lu-bajty\n", sizeof(float));
    printf("Zmienna flt_num zajmuje: %lu-bajty\n", sizeof flt_num);
    printf("Dane typu double zajmuja: %lu-bajtow\n", sizeof(double));
    printf("Zmienna dbl_num zajmuje: %lu-bajtow\n", sizeof dbl_num);

    return 0;
}

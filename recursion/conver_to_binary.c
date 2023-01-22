/*
    Zamienia liczbe w systemie dziesietnym na liczbe w systemie dwojkowym.
*/

#include <stdio.h>

/**
 * Zamienia liczbe dziesietna na liczbe dwojkowa.
 *
 * @param digit liczba w systemie dziesietnym
 */
void convert_to_binary(int digit);

int main(void) {

    convert_to_binary(8); // 1000
    printf("\n");

    convert_to_binary(3); // 11
    printf("\n");

    convert_to_binary(6); // 110
    printf("\n");

    convert_to_binary(0); // 0
    printf("\n");

    convert_to_binary(1); // 1 
    printf("\n");

    return 0;
}

void convert_to_binary(int digit) {

    if(digit <= 1) {
        printf("%d", digit);
        return ;
    }

    int rest_division = digit % 2;
    
    convert_to_binary(digit / 2);

    printf("%d", rest_division);
}
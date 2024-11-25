/*
    r03z01.c: Eksperyment przepełnienia

    1. Zbadaj, jak zachowuje się Twój system w sytuacji przepełnienia zmiennej 
    całkowitej, przepełnienia zmiennej zmiennoprzecinkowej i niedomiaru 
    zmiennej zmiennoprzecinkowej. Zastosuj metodę doświadczalną — napisz 
    programy, w których występują te problemy.
*/

#include <stdio.h>

int main(void) {

    int digit = 2147483647;
    printf("2147483647 + 1 = %d \n", digit + 1); // int, przepełnienie

    float f_1 = 1.0e38f * 1000.0f;
    printf("1.0e38 * 1000.0 = %f \n", f_1); // float, przepełnienie
        
    float f_2 = 1.0e-37f / 1.0e8f;
    printf("1.0e-37 / 1.0e8 = %f \n", f_2); // float, niedomiar

    return 0;
}

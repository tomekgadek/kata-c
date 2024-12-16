/*
    r07z05.c: Statystyki liczb parzystych i nieparzystych (switch())

    5. Wykonaj ponownie ćwiczenie 3, korzystając z instrukcji 'switch'.
*/

#include <stdio.h>

int main(void) {

    int odd_counter = 0, even_counter = 0;
    int odd_sum = 0, even_sum = 0;

    printf("Podaj liczby: \n");

    for(int digit = 0; ; ) {

        scanf("%d", &digit);

        if(digit == 0) {
            break;
        }

        switch(digit % 2) {

            case 0: {
                even_counter++;
                even_sum += digit;
                break;
            }

            default: {
                odd_counter++;
                odd_sum += digit;
                break;
            }
        }
    }

    printf("Liczba parzystych:     %d \n", even_counter);
    printf("Liczba nieparzystych:  %d \n", odd_counter);
    printf("Srednia parzystych:    %.2f \n", even_sum / (float)even_counter);
    printf("Srednia nieparzystych: %.2f \n", odd_sum / (float)odd_counter);

    return 0;
}
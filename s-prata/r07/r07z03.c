/*
    r07z03.c: Statystyki liczb parzystych i nieparzystych

    3. Napisz program, który pobiera liczby całkowite do momentu wpisania 
    przez użytkownika cyfry 0. Po zakończeniu wczytywania danych wejściowych 
    program powinien wyświetlić ilość wpisanych liczb parzystych 
    (z wyłączeniem zera) i ich średnią wartość oraz ilość wpisanych liczb 
    nieparzystych i ich średnią wartość.
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

        if(digit % 2 == 0) {
            even_counter++;
            even_sum += digit;
        } else {
            odd_counter++;
            odd_sum += digit;
        }
    }

    printf("Liczba parzystych:     %d \n", even_counter);
    printf("Liczba nieparzystych:  %d \n", odd_counter);
    printf("Srednia parzystych:    %.2f \n", even_sum / (float)even_counter);
    printf("Srednia nieparzystych: %.2f \n", odd_sum / (float)odd_counter);

    return 0;
}
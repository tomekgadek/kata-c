/*
    r07z09.c: Liczby pierwsze

    9. Napisz program, który pobiera liczbę całkowitą, po czym wyświetla liczby 
    pierwsze mniejsze lub równe tej liczbie.

    Komentarz:
        Jest to rozwiązani nieoptymalne (naiwne). Można zastosować 
        'Sito Erastotenesa' :)
*/

#include <stdio.h>
#include <stdbool.h>

int main(void) {

    int digit = 0;

    printf("Podaj liczbe calkowita: ");
    scanf("%d", &digit);

    printf("Liczby pierwsze <= %d: \n", digit);
    
    for(int i = 2; i <= digit; i++) {

        bool is_prime = true;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                is_prime = false;
                break;
            }
        }

        if(is_prime) {
            printf("%-3d", i);
        }
    }

    printf("\n");

    return 0;
}

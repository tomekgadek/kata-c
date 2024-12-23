/*
    r08z03.c: Licznik małych i wielkich liter

    3. Napisz program, który odczytuje dane do momentu napotkania końca pliku 
    i wyświetla liczbę małych i wielkich liter. Przyjmij, że kolejnym literom 
    odpowiadają kolejne wartości numeryczne.
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    char input_char = '?';
    int upper_counter = 0, lower_counter = 0;

    while((input_char = getchar()) != EOF) {

        if(isupper(input_char)) {
            upper_counter++;
        } else if(islower(input_char)) {
            lower_counter++;
        }
    }

    printf("\nW tekscie mamy %d duzych liter ", upper_counter);
    printf("i %d malych liter. \n", lower_counter);

    return 0;
}

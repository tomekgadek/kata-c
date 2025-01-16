/*
    r11z11.c: Wyświetlanie danych statystycznych o wczytanym tekscie

    11. Napisz program, który pobiera dane wejściowe do momentu wystąpienia 
    końca pliku, a następnie wyświetla informację o liczbie słów, wielkich 
    liter, małych liter, znaków przestankowych oraz cyfr. Skorzystaj z 
    rodziny funkcji ctype.h.
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    int words_counter = 0;
    int digit_counter = 0;
    int punct_counter = 0;
    int lower_counter = 0;
    int upper_counter = 0;

    puts("Podaj tekst:");

    char character_before = getchar();
    char character_after = '?';

    while((character_after = getchar()) != EOF) {

        if(isdigit(character_before)) {
            digit_counter++;
        }
        
        if(isupper(character_before)) {
            upper_counter++;
        }
        
        if(islower(character_before)) {
            lower_counter++;
        }
        
        if(!isspace(character_before) && isspace(character_after)) {
            words_counter++;
        }
        
        if(ispunct(character_before)) {
            punct_counter++;
        }

        character_before = character_after;
    }

    printf("Liczba malych liter:          %d \n", lower_counter);
    printf("Liczba duzych liter:          %d \n", upper_counter);
    printf("Liczba cyfr:                  %d \n", digit_counter);
    printf("Liczba slow:                  %d \n", words_counter);
    printf("Liczba znakow przestankowych: %d \n", punct_counter);

    return 0;
}

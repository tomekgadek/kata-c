/*
    r04z01.c: Wypisz imię i nazwisko

    1. Napisz program, który pyta o Twoje imię, a następnie o nazwisko, po 
    czym wyświetla je w układzie:
    
    Nazwisko, Imię.
*/

#include <stdio.h>

#define TXT_LIMIT 20 + 1

int main(void) {

    char first_name[TXT_LIMIT];
    char last_name[TXT_LIMIT];
        
    printf("Podaj imie: ");
    scanf("%s", first_name);
    printf("Podaj nazwisko: ");
    scanf("%s", last_name);
        
    printf("%s, %s \n", last_name, first_name);

    return 0;
}
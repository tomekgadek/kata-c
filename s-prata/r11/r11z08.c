/*
    r11z08.c: Funkcja, która odwraca zawartość łańcucha

    8. Napisz funkcję, która odwraca zawartość łańcucha i zapisuje ją w tym 
    samym łańcuchu.
*/

#include <stdio.h>

char *reverse(char *);

int main(void) {

    char word[] = "Hello Mike!";

    char *rev = reverse(word);
    printf("Rezultat: %s \n", rev);

    return 0;
}

char *reverse(char *message) {

    char *begin = message, *start = message, *stop = message;

    while(*(++stop) != '\0');

    /* 
        Zamieniam pierwszy element z ostatnim. 
        Zbliżam się do środka aż do spotkania :)
    */
    stop -= 1;
    for(char swap = '?'; start < stop; start++, stop--) {
        
        swap = *start;
        *start = *stop;
        *stop = swap;
    }

    return begin;
}

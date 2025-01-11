/*
    r11z06.c: Własna implementacja funkcji strncpy()

    6. Funkcja strncpy(s1, s2, n) kopiuje z s2 do s1 dokładnie n znaków, w 
    razie potrzeby skracając łańcuch s2 lub dodając do niego znaki zerowe. 
    Łańcuch wynikowy może nie kończyć się znakiem zerowym, jeśli długość 
    s2 wynosi n lub więcej. Wartością zwracaną jest s1. Napisz swoją 
    własną wersję tej funkcji.
*/

#include <stdio.h>

#define ARRAY_SIZE 10 + 1

char *my_strncpy(char *, char *, int);

int main(void) {

    char message_src[ARRAY_SIZE] = "Test_1";
    char message_dest[ARRAY_SIZE] = "Test_2";
    
    char *result = my_strncpy(message_dest, message_src, 3);

    printf("Source:      %s \n", message_src);
    printf("Destination: %s \n", result);

    return 0;
}

char *my_strncpy(char * dest, char * src, int n) {

    int i = 0;
    while(i < n) {

        dest[i] = src[i];

        if(dest[i] == '\0') {
            break;
        }

        i++;
    }

    if(src[i] != '\0') {
        dest[i] = '\0';
    }

    return dest;
}

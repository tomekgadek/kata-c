/*
    r04z02.c: Formatowanie tekstu

    2. Napisz program, który pyta o Twoje imię, a następnie:
    
    a. wyświetla je w cudzysłowie.
    b. wyświetla je w polu o szerokości 20 znaków; w cudzysłów powinno być ujęte całe pole.
    c. wyświetla je przy lewym brzegu pola o szerokości 20 znaków; w cudzysłów powinno być ujęte całe pole.
    d. wyświetla je w polu o trzy znaki dłuższym niż imię.
*/

#include <stdio.h>
#include <string.h>

const int TXT_LIMIT = 20 + 1;

int main(void) {

    char first_name[TXT_LIMIT];
        
    printf("Podaj imie: ");
    scanf("%s", first_name);
        
    printf("\"%s\"    \n", first_name);
    printf("\"%20s\"  \n", first_name);
    printf("\"%-20s\" \n", first_name);
    printf("\"%*s\"   \n", (int)(strlen(first_name)+3), first_name);

    return 0;
}

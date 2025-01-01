/*
    r09z05.c: Czy to litera?

    5. Napisz program, który odczytuje znaki z wejścia standardowego aż do 
    wystąpienia końca pliku. Dla każdego znaku program powinien informować, 
    czy jest on literą. Jeśli tak, program powinien również wyświetlić numer 
    litery w alfabecie. Na przykład, litery 'c' i 'C' obie mają numer 3. 
    Wykorzystaj funkcję, która pobiera znak jako argument i zwraca jego 
    numer w alfabecie, jeśli jest on literą; w przeciwnym przypadku 
    wartością zwracaną powinno być '-1'.
*/

#include <stdio.h>

int recognize_character(char);

int main(void) {

    printf("Wprowadz tekst: ");
        
    for(int ch = '?'; (ch = getchar()) != EOF; ) {

        int char_pos = recognize_character(ch);
        printf("\n%c = %d", ch, char_pos);
        printf("\n%s.", (char_pos != -1 ? "To jest litera" : "To nie jest litera"));
    }

    printf("\n");

    return 0;
}

int recognize_character(char ch) {

    if(ch >= 'a' && ch <= 'z') {

        return ch - 'a' + 1;
    }

    if(ch >= 'A' && ch <= 'Z') {

        return ch - 'A' + 1;
    }

    return -1;
}

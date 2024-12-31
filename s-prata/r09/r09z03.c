/*
    r09z03.c: Wyświetlanie znaków w wierszach

    3. Napisz funkcję, która pobiera trzy argumenty: znak oraz dwie liczby 
    całkowite. Pierwsza liczba określa liczbę razy, jaką należy wyświetlić 
    znak w jednym wierszu; druga liczba określa liczbę wierszy. Napisz 
    program, który wykorzystuje tę funkcję.
*/

#include <stdio.h>

void print_char_at_row(char ch, int counter, int rows);

int main(void) {

    print_char_at_row('*', 7, 10);

    return 0;
}

void print_char_at_row(char ch, int counter, int rows) {

    for(int i = 1; i <= rows; i++) {

        printf("%2d: ", i);
        for(int j = 0; j < counter; j++) {
            putchar(ch);
        }

        putchar('\n');
    }
}

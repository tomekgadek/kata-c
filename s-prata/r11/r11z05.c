/*
    r11z05.c: Czy znak znajduje się w łańcuchu?

    5. Napisz funkcję zawiera (), pobierającą jako argumenty znak oraz łańcuch 
    i zwracającą wartość niezerową (prawdę), jeśli znak znajduje się w 
    łańcuchu, a w przeciwnym wypadku - wartość 0.
*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool zawiera(char * message, char search_char);

int main(void) {

    char message[] = "Szkola programowania!";
    
    char char_exists = 'o';
    char char_not_exists = '?';

    assert(zawiera(message, char_exists) == true);
    assert(zawiera(message, char_not_exists) == false);

    return 0;
}

bool zawiera(char * message, char search_char) {

    while(* message) {

        if(*message == search_char) {
            return true;
        }

        message++;
    }

    return false;
}

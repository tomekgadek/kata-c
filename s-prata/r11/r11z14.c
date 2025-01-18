/*
    r11z14.c: Własna implementacja funkcji atoi()

    14. Korzystając z funkcji klasyfikujących znaki wykonaj własną 
    implementację funkcji atoi().
*/

#include <stdio.h>
#include <ctype.h>
#include <assert.h>

int my_atoi(char *);
int to_number(char);

int main(void) {

    assert(my_atoi("12a") == 12);
    assert(my_atoi("12a0") == 12);
    assert(my_atoi("-12a0") == -12);
    assert(my_atoi("-12 5a0") == -12);
    assert(my_atoi("-a10") == 0);
    assert(my_atoi("a") == 0);
    assert(my_atoi("a") == 0);
    assert(my_atoi("--12") == 0);
    assert(my_atoi("-016") == -16);

    return 0;
}

int my_atoi(char *message) {

    char *first_letter = message;

    if(*first_letter == '-' || *first_letter == '+') {
        message += 1;
    }
    
    while(isdigit(*message)) {
        message++;
    }

    message -= 1;

    int base = 1; // zaczynamy od jednosci (od prawej strony)
    int result = 0;

    while(first_letter <= message) {

        if(*message == '-') {
            result *= -1;
            break;
        } else if(*message == '+') {
            break;
        }

        result += (to_number(*message) * base);
    
        base *= 10; // jednostki, dziesitki, tysiace, etc.
        message -= 1;
    }
        
    return result;
}

int to_number(char character) {

    return character - '0';
}

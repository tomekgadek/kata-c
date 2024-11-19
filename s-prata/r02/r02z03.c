/*
    r02z03.c: Program przeliczający wiek użytkownika na dni

    3. Napisz program przeliczający Twój wiek w latach na wiek w dniach. 
    Nie uwzględniaj ułamków lat oraz lat przestępnych.
*/

#include <stdio.h>

#define DAYS_IN_YEAR 365

int main(void) {
    
    int user_age = 33;
    
    int age_in_days = (user_age * DAYS_IN_YEAR);
    
    printf("Moj wiek to %d lata, czyli %d dni. \n", user_age, age_in_days);

    return 0;
}

/*
    r04z04.c: Wzrost użytkownika

    4. Napisz program, który pobiera Twój wzrost w centymetrach oraz Twoje 
    imię, a następnie wyświetla te dane w następującej postaci:
    
    Robert, masz 1.82 metra wzrostu.
    
    Użyj typu float, a dzielenie wykonaj za pomocą operatora /.
*/

#include <stdio.h>

const int TXT_LIMIT = 20 + 1;

int main(void) {

    float height = 0.0f, height_in_centimeters = 0.0f;
    char first_name[TXT_LIMIT]; 
        
    printf("Podaj swoj wzrost w [cm]: ");
    scanf("%f", &height_in_centimeters);

    height = height_in_centimeters / 100.0f;
        
    printf("Podaj swoje imie: ");
    scanf("%s", first_name);
        
    printf("%s, masz %.2f metra wzrostu. \n", first_name, height);

    return 0;
}

/*
    r11z04.c: Funkcja podobna do funkcji bibliotecznej strchr()

    4. Zaprojektuj funkcję, która przegląda łańcuch w poszukiwaniu zadanego 
    znaku. Jeśli znak zostanie znaleziony, funkcja powinna zwracać wskaźnik 
    do znaku; w przeciwnym wypadku powinna ona zwracać wskaźnik zerowy. 
    (W ten sposób działa funkcja bibliotekowa strchr().)
*/

#include <stdio.h>
#include <string.h>

char * my_strchr(char * message, char search_char);

int main(void) {

    char message[] = "Szkola programowania!";
    char *result = my_strchr(message, 'a');

    printf("Przed: %s \n", message);
    printf("Po   : %s \n", result);

    return 0;
}

char * my_strchr(char * message, char search_char) {

    for( ; * message != search_char; message++);

    if(* message != '\0') {

        return message;
    }

    return NULL;
}

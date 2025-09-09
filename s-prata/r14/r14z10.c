/*
    r14z10.c: Menu przy użyciu tablicy wskaźnikow do funkcji

    10. Napisz program, który realizuje menu za pomocą tablicy wskaźników do 
    funkcji. Na przykład, wybranie opcji a powodowałoby uruchomienie funkcji 
    wskazywanej przez pierwszy element tablicy.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void upper(const char *);
void lower(const char *);
void reverse(const char *);
int menu(const char *);
void pause_program(void);

const int AVAILABLE_OPERATIONS = 3;
const char MESSAGE[] = "Wiem, ze nic nie wiem. Sokrates";

int main(void) {

    void (*opt[AVAILABLE_OPERATIONS])(const char *) = { upper, lower, reverse };

    for(int operation = 0; (operation = menu(MESSAGE)) != AVAILABLE_OPERATIONS; ) {

        opt[operation](MESSAGE);
        pause_program();
    }

    printf("Koniec programu. \n");

    return 0;
}

void upper(const char *message) {

    for(int i = 0; message[i] != '\0'; i++) {
        putchar(toupper(message[i]));
    }

    putchar('\n');
}

void lower(const char *message) {

    for(int i = 0; message[i] != '\0'; i++) {
        putchar(tolower(message[i]));
    }

    putchar('\n');

}

void reverse(const char *message) {

    int length = strlen(message);

    for(int i = length - 1; i >= 0; i--) {
        putchar(message[i]);
    }

    putchar('\n');
}

int menu(const char *message) {

    printf("Menu glowne (Zapisz cytat \'%s\' w odpowiedniej formie). \n", message);
    printf("0) Wielkimi literami. \n");
    printf("1) Malymi literami. \n");
    printf("2) Wspak. \n");
    printf("3) Koniec programu. \n");
    printf(":: ");

    int option = 0;
    if(scanf("%d", &option) != 1 || option < 0 || option > AVAILABLE_OPERATIONS) {
        option = AVAILABLE_OPERATIONS;
    }

    while(getchar() != '\n');

    return option;
}

void pause_program(void) {

    printf("\nNaciśnij Enter, aby kontynuować...\n");
    getchar();
}

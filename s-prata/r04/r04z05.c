/*
    r04z05.c: Formatowanie tekstu i wykorzystanie funkcji strlen()

    5. Napisz program, który pobiera imię i last_name użytkownika, po czym 
    wyświetla: w pierwszym wierszu imię i last_name, a w drugim liczbę liter 
    w first_nameniu i nazwisku. Każda z liczb powinna znajdować się pod ostatnią 
    literą odpowiadającego jej wyrazu, tak jak poniżej:

    Anne Kleine-Nachtmusik  
       4                17

    Następnie zmień program tak, aby liczby były zrównane z pierwszymi 
    literami first_namenia i nazwiska:

    Anne Kleine-Nachtmusik  
    4    17
*/

#include <stdio.h>
#include <string.h>

const int TXT_LIMIT = 20 + 1;

int main(void) {

    char first_name[TXT_LIMIT], last_name[TXT_LIMIT]; 

    printf("Podaj imie i nazwisko: ");
    scanf("%s %s", first_name, last_name);

    int fn_size = strlen(first_name);
    int ln_size = strlen(last_name);

    printf("%s %s \n", first_name, last_name);
    printf("%*.d %*.d \n", fn_size, fn_size, ln_size, ln_size);

    printf("\n");

    printf("%s %s\n", first_name, last_name);
    printf("%-*.d %-*.d \n", fn_size, fn_size, ln_size, ln_size);

    return 0;
}

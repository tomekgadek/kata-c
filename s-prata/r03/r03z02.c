/*
    r03z02.c: Kod ASCII

    2. Napisz program, który prosi o podanie kodu ASCII, np. 66, a 
    następnie wyświetla znak odpowiadający temu kodowi.
*/

#include <stdio.h>

int main(void) {

    int sign;
        
    printf("Podaj kod ASCII: ");
    scanf("%d", &sign);

    printf("Kod %d = znak %c \n", sign, sign);

    return 0;
}

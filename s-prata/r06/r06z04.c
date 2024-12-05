/*
    r06z04.c: Zbuduj piramidę znakową

    4. Napisz program, który pobiera od użytkownika wielką literę, a następnie
    wyświetla poniższą "piramidę", korzystając z pętli zagnieżdżonych:  

        A  
       ABA  
      ABCBA  
     ABCDCBA  
    ABCDEDCBA
    
    Wzór powinien kończyć się na wpisanym przez użytkownika znaku. Na 
    przykład, powyższy obraz byłby wynikiem podania litery E.  
    
    Wskazówka:
    Do utworzenia rzędów użyj pętli zewnętrznej. Zawartość 
    poszczególnych rzędów skonstruuj za pomocą trzech pętli 
    wewnętrznych: wyświetlającej początkowe odstępy, wyświetlającej litery 
    w kolejności rosnącej oraz wyświetlającej litery w kolejności malejącej.
*/

#include <stdio.h>

int main(void) {

    printf("Podaj wielka litere: ");
    char sign_end = getchar();

    char sign_start = 'A';

    int shift = sign_end - sign_start;

    for(char ch = sign_start; ch <= sign_end; ch++) {

        for(int i = 0; i < shift; i++) {
            putchar(' ');
        }

        for(char left_sign = sign_start; left_sign <= ch; left_sign++) {
            putchar(left_sign);
        }

        for(char right_sign = ch - 1; right_sign >= sign_start; right_sign--) {
            putchar(right_sign);
        }

        putchar('\n');

        shift -= 1;
    }

    putchar('\n');

    return 0;
}

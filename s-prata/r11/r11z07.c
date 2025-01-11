/*
    r11z07.c: Czy łańcuch zawiera się w drugim łańcuchu

    7. Napisz funkcję zawiera_lan(), która pobiera jako argumenty dwa 
    wskaźniki łańcuchowe. Jeśli drugi łańcuch zawiera się w pierwszym 
    łańcuchu, funkcja powinna zwrócić adres, pod którym rozpoczyna się 
    ten łańcuch. Na przykład, wywołanie zawiera lan ("pula", "ul") powinno 
    zwrócić adres litery u w słowie pula. Jeśli drugi łańcuch nie zawiera 
    się w pierwszym łańcuchu, zwracaną wartością powinien być wskaźnik zerowy.
*/

#include <stdio.h>

char *zawiera_lan(char *, char *);

int main(void) {

    char first[] = "AtotomekTo";
    char second[] = "tom";

    char *sub = zawiera_lan(first, second);
    printf("Rezultat: %s \n", sub);

    return 0;
}

char *zawiera_lan(char *s1, char *s2) {

    char *substring = NULL;

    for(int i = 0; s1[i] != '\0' && substring == NULL; i++) {

        if(s1[i] != s2[0]) {
            continue;
        }

        substring = &s1[i];

        for(int j = 0; s2[j] != '\0'; j++, i++) {

            if(s2[j] != s1[i]) {
                i -= 1;
                substring = NULL;
                break;
            }
        }
    }

    return substring;
}

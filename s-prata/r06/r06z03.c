/*
    r06z03.c: Zbuduj trójkąt zawierający znaki F..A

    3. Użyj pętli zagnieżdżonych, aby uzyskać następujący wzór:  

    F
    FE
    FED
    FEDC
    FEDCB
    FEDCBA
*/

#include <stdio.h>

int main(void) {

    char char_stop = 'A';

    for(char char_start = 'F'; char_start >= char_stop; char_start--) {

        for(char char_inline = 'F'; char_inline >= char_start; char_inline--) {
            putchar(char_inline);
        }

        putchar('\n');
    }

    putchar('\n');

    return 0;
}

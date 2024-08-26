/* 12L05.c: Stop po napotkaniu znaku \0 */

#include <stdio.h>

int main(void) {

    char array_ch[15] = { 
        'C', ' ',
        'i', 's', ' ',
        'p', 'o', 'w', 'e', 'r',
        'f', 'u', 'l', '!', '\0'
    };

    int i;
    
    for(i = 0; array_ch[i] != '\0'; i++)
        printf("%c", array_ch[i]);

    return 0;
}

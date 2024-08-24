/* 09L01.c: Modyfikatory signed i unsigned, format binarny */

#include <stdio.h>

/* funkcja druk_bin drukuje podany argument dziesietny typu int binarnie */
void druk_bin(int x) {
    int n;

    for(n=15;n>=0;n--) {
        ((x >> n) & 1) ? putchar('1') : putchar('0');
    }
}

int main(void) {

    signed char ch;
    int x;
    unsigned int y;
    
    ch = 0xFF;
    x = 0xFFFF;
    y = 0xFFFF;
    
    printf("\nDziesietnie ze znakiem 0xFF to: %d", ch);
    printf("\nDziesietnie ze znakiem\n0xFFFF to: %d a Binarnie: ", x);
    druk_bin(0xFFFF);
    printf("\nDziesietnie bez znaku 0xFFFF to: %u", y);
    printf("\nDzies.: 12345 to Hex: 0x%X i Binarnie:", 12345);
    druk_bin(12345);
    printf("\nDzies.: -12345 to Hex: 0x%X i Binarnie:", -12345);
    druk_bin(-12345);

    return 0;
}    

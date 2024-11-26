/*
    r03z03.c: Sygnał

    3. Napisz program, który wydaje sygnał dźwiękowy, po czym wyświetla 
    następujący tekst:
    
        Sally, przerazona niespodziewanym odglosem, krzyknela 
        "A niech mnie, co to bylo!?"
*/

#include <stdio.h>

int main(void) {

    printf("\a");

    printf("Sally, przerazona niespodziewanym odglosem, krzyknela ");
    printf("\"A niech mnie, co to bylo !?\"");

    putchar('\n');
    return 0;
}

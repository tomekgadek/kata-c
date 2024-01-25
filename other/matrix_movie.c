/*
    Program wyswietla tekst "Matrix cie wiezi..." znak po znaku - motyw z filmu
    'Matrix'.
*/

#include <stdio.h>
#include <string.h>

/**
 * Usypia wątek na pewien czas.
 * 
 * @param limit wartość dla pętli, w celu ograniczenia iteracji.
 *
 */
void sleep(long limit);

int main(void) {

    char message[] = "Matrix cie wiezi... \n";

    for(int i = 0; i < strlen(message); i++) {
        sleep(50000000);
        fflush(stdout);
        putchar(message[i]);
    }

    return 0;
}

void sleep(long value) {
    for(long i = 0; i < value; i++);
}

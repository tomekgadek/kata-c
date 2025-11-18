/*
    fence.c

    Temat: 
    Szyfry klasyczne (Szyfr płotkowy).

    Opis:
    Szyfr płotkowy – szyfr przestawieniowy, opisywany przez pewną liczbę 'n', 
    oznaczającą "wysokość" tworzonych schodków – kolejne litery tekstu jawnego 
    zapisywane są na zmianę w n rzędach. Kryptogram tworzony jest poprzez 
    połączenie ciągu kolejnych liter pierwszego rzędu, po którym 
    umieszcza się rząd drugi, itd.

    Źródło: 
    https://pl.wikipedia.org/wiki/Szyfr_płotkowy
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fence.h"

int main(void) {

    char input[] = "KRYPTOGRAFIA";
    int data_size = strlen(input);

    fen_t * fen = create_fence(data_size, KEY);
    char * output_encode = encode(input, fen, KEY);
    char * output_decode = decode(output_encode, fen, KEY);

    printf("message: %s \n", input);
    printf("encode:  %s \n", output_encode);
    printf("decode:  %s \n", output_decode);

    free(fen);
    free(output_encode);
    free(output_decode);

    return 0;
}
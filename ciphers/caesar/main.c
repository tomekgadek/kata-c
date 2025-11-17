/*
    caesar.c

    Temat: 
    Szyfry klasyczne (Szyfr Cezara).

    Opis:
    Szyfr Cezara - jedna z najprostszych technik szyfrowania. Jest to rodzaj 
    szyfru podstawieniowego, w którym każda litera tekstu jawnego 
    (niezaszyfrowanego) zastępowana jest inną, oddaloną od niej o stałą liczbę 
    pozycji w alfabecie, literą (szyfr monoalfabetyczny), przy czym kierunek 
    zamiany musi być zachowany. Nie rozróżnia się przy tym liter dużych i 
    małych. Nazwa szyfru pochodzi od Juliusza Cezara, który prawdopodobnie 
    używał tej techniki do komunikacji ze swymi przyjaciółmi.

    Źródło: 
    https://pl.wikipedia.org/wiki/Szyfr_Cezara
*/

#include <stdio.h>
#include <stdlib.h>

#include "caesar.h"

int main(void) {

    char input[] = "KRYPTOGRAFIA";

    char * output_encode = encode(input, KEY);
    char * output_decode = decode(output_encode, KEY);

    printf("message: %s \n", input);
    printf("encode:  %s \n", output_encode);
    printf("decode:  %s \n", output_decode);

    free(output_encode);
    free(output_decode);

    return 0;
}

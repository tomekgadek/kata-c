/*
    r12z01.c: Kopiowanie plików

    1. Napisz program kopiujący pliki, który pobiera nazwę pliku źródłowego i 
    docelowego z wiersza po-leceń. Skorzystaj ze standardowego wejścia/wyjścia 
    i trybu binarnego. 
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc != 3) {

        printf("Prawidlowe uruchomienie programu: ./a.out plik_we plik_wy \n");
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen(argv[1], "rb");
    FILE *output_file = fopen(argv[2], "wb");

    if(input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Blad otwarcia plikow. \n");
        exit(EXIT_FAILURE);
    }

    printf("Kopiuje dane... \n");
    for(char character = '?'; (character = fgetc(input_file)) != EOF; ) {

        putchar(character);
        fputc(character, output_file);
    }

    printf("\n");

    fclose(input_file);
    fclose(output_file);

    printf("Koniec. \n");

    return EXIT_SUCCESS;
}

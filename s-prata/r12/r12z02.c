/*
    r12z02.c: Zbiorowy odczyt plików z linii poleceń

    2. Napisz program, który wyświetla kolejno na ekranie wszystkie pliki, 
    których nazwy podano w wierszu poleceń. Użyj pętli sterowanej 
    zmienną argc. 
*/

#include <stdio.h>
#include <stdlib.h>

void open_file(char *);

int main(int argc, char *argv[]) {

    if(argc == 1) {
        printf("Sposob uzycia: %s plik1 plik2 plik3... \n", argv[0]);
        exit(1);
    }

    for(int i = 1; i < argc; i++) {
        open_file(argv[i]);
    }

    return 0;
}

void open_file(char *filename) {

    const int FILE_CONTENT = 128;

    FILE *file = NULL;
    char content[FILE_CONTENT];

    file = fopen(filename, "r");

    if(file == NULL) {
        fprintf(stderr, "!!! Nie moge otworzyc pliku %s. !!!\n", filename);
        return ;
    }

    printf("Otworzylem plik %s. \n", filename);

    while(fgets(content, FILE_CONTENT, file) != NULL) {

        fputs(content, stdout);
    }

    printf("\n=== \n");

    fclose(file);
}

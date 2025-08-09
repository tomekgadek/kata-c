/*
    r12z06.c: Zliczanie wystąpień znaku w plikach

    6. Napisz program, który przyjmuje jako argumenty wiersza poleceń jeden 
    znak oraz zero lub więcej nazw plików. Jeśli po znaku nie występują żadne 
    argumenty program powinien pobierać dane z wejścia standardowego. W 
    przeciwnym wypadku, program powinien otwierać każdy kolejny plik i podawać 
    liczbę razy, jaką występuje w nim zadany znak. Obok liczby wystąpień na 
    ekranie powinna widnieć nazwa pliku oraz poszukiwany znak. Pamiętaj o 
    wykrywaniu błędów: sprawdzeniu, czy liczba argumentów jest 
    prawidłowa, oraz czy plik może zostać otwarty. Jeśli otwarcie pliku 
    jest niemożliwe, program powinien zgłaszać ten fakt, po czym przejść do 
    następnego pliku.
*/

#include <stdio.h>

int count_characters_from_file(FILE *, char);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        puts("Za malo argumentow!");
        return 1;
    }
    
    if (argc == 2) {
        puts("Podaj tekst (EOF = koniec): ");
        int sign_count = count_characters_from_file(stdin, argv[1][0]);
        printf("Znak \'%c\' wystapil %d razy. \n", argv[1][0], sign_count);

        return 0;
    }

    FILE *file = NULL;

    for (int i = 2; i < argc; i++) {
        file = fopen(argv[i], "r");
        if (file == NULL) {
            fprintf(stderr, "Nie otwarto pliku %s. \n", argv[i]);
            continue;
        }

        printf("Otwarto %s, ", argv[i]);

        int sign_count = count_characters_from_file(file, argv[1][0]);
        printf("\'%c\' wystapilo %d razy. \n", argv[1][0], sign_count);
        
        fclose(file);
    }

    return 0;
}

int count_characters_from_file(FILE *file, char sign) {
    int counter = 0;
    char ch = ' ';

    while ((ch = getc(file)) != EOF) {
        if (ch == sign) {
            counter++;
        }
    }

    return counter;
}

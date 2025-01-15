/*
    r11z10.c: Operacje na łańcuchach znaków

    10. Napisz program, który wczytuje maksymalnie 10 łańcuchów i kończy 
    odczytywanie w przypadku wystąpienia końca pliku. Powinien on wyświetlać 
    menu zawierające pięć opcji: (1) wyświetlenie pierwotnej listy łańcuchów, 
    (2) wyświetlenie łańcuchów w porządku ASCII, (3) wyświetlenie łańcuchów 
    według długości (rosnąco), (4) wyświetlenie łańcuchów według długości 
    pierwszego słowa oraz (5) koniec. Menu powinno być wyświetlane dopóty, 
    dopóki użytkownik nie wybierze opcji nr 5. Rzecz jasna, program powinien 
    rzeczywiście wykonywać zapowiedziane czynności.
*/

#include <stdio.h>
#include <string.h>

#define DATA_SIZE 10
#define LINE_SIZE 1024

// private
int _first_word_size(char *);

// public
void menu(void);
int insert(char words[][LINE_SIZE], int);
void show_lines(char *[], int);
void sort_ascii(char *[], int);
void sort_by_length(char *[], int);
void sort_by_first_word(char *[], int);

// main
int main(void) {

    char words[DATA_SIZE][LINE_SIZE];
    char *main[DATA_SIZE], *copy[DATA_SIZE];

    printf("Wprowadz tekst (max %d linii): \n", DATA_SIZE);
    int size = insert(words, DATA_SIZE);

    // copy data
    for(int i = 0; i < size; i++) {
        main[i] = copy[i] = &words[i][0];
    }

    for(int option = 1; option > 0 && option != 5; ) {
        menu();

        if(scanf("%d", &option) != 1) {
            break;
        }

        switch(option) {
            case 1: show_lines(main, size); break;
            case 2: sort_ascii(copy, size); break;
            case 3: sort_by_length(copy, size); break;
            case 4: sort_by_first_word(copy, size); break;
        }
    }

    return 0;
}

int _first_word_size(char *line) {

    int size = 0;
        
    for(int i = 0; line[i] != '\0'; i++) {

        size++;
        if(line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
            break;
        }
    }

    return size;        
}

void menu(void) {

    printf("*) ===                menu                === \n");
    printf("1) Wyswitl pierwotna liste.                 = \n");
    printf("2) Wyswietl lancuch w porzadku ASCII.       = \n");
    printf("3) Wyswietl lancug wg. dlugosci (rosnaco).  = \n");
    printf("4) Wyswietl lancug wg. dlugosci 1-ego slowa.= \n");
    printf("5) Koniec.                                  = \n");
    printf("*) ===                menu                === \n\n");

    printf(">> ");
}

int insert(char words[][LINE_SIZE], int limit) {

    int size = 0;
    while(size < limit && fgets(words[size], LINE_SIZE, stdin) != NULL) {

        if(words[size][1] == '\0') {
            break;
        } else {
            words[size][strlen(words[size])-1] = '\0';
        }

        size += 1;
    }

    return size;
}

void show_lines(char *lines[], int size) {

    for(int i = 0; i < size; i++) {
        printf("%d) %s \n", i+1, lines[i]);
    }

    printf("\n");
}

void sort_ascii(char *lines[], int size) {

    for(int i = 0; i < size; i++) {

        for(int j = 0; j < size - 1; j++) {

            if(strcmp(lines[j], lines[j+1]) > 0) {
                char *swap = lines[j];
                lines[j] = lines[j+1];
                lines[j+1] = swap;
            }
        }
    }

    show_lines(lines, size);
}

void sort_by_length(char *lines[], int size) {

    for(int i = 0; i < size; i++) {

        for(int j = 0; j < size - 1; j++) {

            if(strlen(lines[j]) > strlen(lines[j+1])) {
                char *swap = lines[j];
                lines[j] = lines[j+1];
                lines[j+1] = swap;
            }
        }
    }

    show_lines(lines, size);
}

void sort_by_first_word(char *lines[], int size) {

    for(int i = 0; i < size; i++) {

        for(int j = 0; j < size - 1; j++) {

            if(_first_word_size(lines[j]) > _first_word_size(lines[j+1])) {
                char *swap = lines[j];
                lines[j] = lines[j+1];
                lines[j+1] = swap;
            }
        }
    }

    show_lines(lines, size);
}

/*
>> 4
1) Lala 
2) Ala ma kota 
3) Tomek romek i atom 
4) ALicja w krainie 

>> 1
1) Ala ma kota 
2) ALicja w krainie 
3) Tomek romek i atom 
4) Lala 
*/
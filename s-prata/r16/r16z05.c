/*
    r16z05.c: Program zapisujący nazwy programów telewizyjnych do pliku

    5. Zmodyfikuj program z listingu 16.12 tak, aby zamiast liczb przetwarzał 
    nazwy programów telewizyjnych i zapisywał łańcuchy w pliku. Jeśli w momencie 
    uruchomienia programu plik już istnieje, program powinien najpierw odczytać 
    jego zawartość i wyświetlić ją na ekranie. Wszystkie łańcuchy powinny być 
    przechowywane w rekordach o tym samym rozmiarze. Skorzystaj z funkcji 
    fread() i fwrite().
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME  50
#define FILE_NAME "static/tv.dat"

void read_tv_program(const char *nazwa_pliku);
bool save_tv_program(const char *filename, char (*ptr_tv)[MAX_NAME], int tv_counter);
int input_data(char (*ptr_tv)[MAX_NAME], int max_input_data);

int main(void) {

    read_tv_program(FILE_NAME);

    printf("\nIle maksymalnie nazw programow TV chcesz dodac? \n");

    int max_input_data = 0;
    scanf("%d", &max_input_data);

    while(getchar() != '\n');

    char (*ptr_tv)[MAX_NAME];
    ptr_tv = (char (*)[MAX_NAME]) malloc(max_input_data * sizeof(*ptr_tv));

    if (ptr_tv == NULL) {
        fprintf(stderr, "Błąd przydzialu pamięci. \n");
        exit(EXIT_FAILURE);
    }

    printf("Wpisuj kolejne nazwy programów (pusta linia kończy): \n");

    int tv_counter = input_data(ptr_tv, max_input_data);

    if(tv_counter <= 0) {
        fprintf(stderr, "Brak danych do zapisania. \n");
        free(ptr_tv);
        return 1;
    }

    bool result = save_tv_program(FILE_NAME, ptr_tv, tv_counter);

    if(!result) {
        fprintf(stderr, "Błąd zapisu do pliku. \n");
        free(ptr_tv);
        return 2;
    }

    printf("\nDodano %d nowych programów.\n", tv_counter);

    free(ptr_tv);

    return 0;
}

void read_tv_program(const char *nazwa_pliku) {

    FILE *fp = fopen(nazwa_pliku, "rb");

    if (fp != NULL) {

        char buf[MAX_NAME];
        printf("Zawartość istniejącego pliku: \n");

        while (fread(buf, sizeof(buf), 1, fp) == 1) {

            buf[MAX_NAME - 1] = '\0';
            printf("%s \n", buf);
        }

        fclose(fp);
    }
}

bool save_tv_program(const char *filename, char (*ptr_tv)[MAX_NAME], int tv_counter) {

    FILE *fp = fopen(filename, "ab");

    if (fp == NULL) {
        return false;
    }

    for (int i = 0; i < tv_counter; i++) {
        fwrite(ptr_tv[i], sizeof(*ptr_tv), 1, fp);
    }

    fclose(fp);

    return true;
}

int input_data(char (*ptr_tv)[MAX_NAME], int max_input_data) {
    
    int tv_counter = 0;
    while (tv_counter < max_input_data && fgets(ptr_tv[tv_counter], MAX_NAME, stdin) != NULL) {
        
        ptr_tv[tv_counter][strcspn(ptr_tv[tv_counter], "\n")] = '\0';
        if (ptr_tv[tv_counter][0] == '\0') {
            break;
        }
        ++tv_counter;
    }

    return tv_counter;
}

/*
    r14z08.c: Linie lotnicze Colossus - program do rezerwacji miejsc

    8. Flota linii lotniczych Colossus składa się z jednego samolotu o 12 
    miejscach. Samolot ten odbywa jeden rejs dziennie. Napisz program do 
    rezerwacji miejsc spełniający następujące warunki:

    a. Program wykorzystuje tablicę 12 struktur. Każda z nich powinna 
       przechowywać numer identyfikacyjny miejsca, znacznik określający, czy 
       miejsce jest wolne, oraz imię i nazwisko osoby, która dokonała rezerwacji.
    b. Program wyświetla poniższe menu:
    
          Aby wybrać opcję, wpisz jej oznaczenie literowe:
       
          a. Pokaż liczbę pustych miejsc
          b. Pokaż listę pustych miejsc
          c. Pokaż alfabetyczną listę miejsc
          d. Zarezerwuj miejsce dla klienta
          e. Usuń rezerwację miejsca
          f. Koniec

    c. Program wykonuje czynności zapowiedziane w menu. Opcje d) i e) wymagają 
       podania dodatkowych danych; każda z nich powinna umożliwić przerwanie 
       wpisywania.
    d. Po wykonaniu jednej z funkcji program powinien ponownie wyświetlić menu 
       (nie dotyczy opcji f)).
    e. Informacje o rezerwacjach są przechowywane w pliku.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SEATS    12
#define TXT_SIZE 20 + 1
#define RESERVATION_FILE "static/colossus.txt"

struct colossus {
    int seat_id;
    char reserved;
    char first_name[TXT_SIZE];
    char last_name[TXT_SIZE];
};

char menu(void);

void init_data(struct colossus *, int);
int count_empty_seats(struct colossus *, int);
char *list_empty_seats(struct colossus *, int);

void sort(struct colossus *, int);

bool create_reservation(struct colossus *, int);
bool cancel_reservation(struct colossus *, int);

int load_data_from_file(struct colossus *, int, char []);
int save_data_to_file(struct colossus *, int, char []);

int main(void) {

    struct colossus concorde[SEATS];

    init_data(concorde, SEATS);
    
    if(load_data_from_file(concorde, SEATS, RESERVATION_FILE) != 0) {
        fprintf(stderr, "Blad wczytywania danych z pliku. \n");
        printf("Postaram sie kontynuowac. \n");
        if(save_data_to_file(concorde, SEATS, RESERVATION_FILE) != 0) {
            fprintf(stderr, "Blad tworzenia pliku. \n");
        } else {
            printf("Utworzono plik z danymi. \n");
            if(load_data_from_file(concorde, SEATS, RESERVATION_FILE) == 0) {
                printf("Wczytano dane z pliku. \n");
            } else {
                fprintf(stderr, "Nadal nie moge wczytac danych z pliku. \n");
                return 1;
            };
        }
    };

    char option = ' ';
    while ((option = menu()) != 'f') {
        switch (option) {
            case 'a': {
                printf("%02d \n", count_empty_seats(concorde, SEATS));
                break;        
            }
            case 'b': {       
                char *seats = list_empty_seats(concorde, SEATS);
                printf("Lista miejsc (O - wolne, X - zajete): \n");
                for (int i = 0; i < SEATS; i++) {
                    if(seats[i] == 'X') {
                        continue;
                    }

                    printf("(%02d, %c) ", i, seats[i]);
                }
                printf("\n");

                free(seats);
                break;
            }
            case 'c': {
                sort(concorde, SEATS);
                for(int i = 0; i < SEATS; i++) {
                    printf("%02d). %c %s %s \n", 
                        concorde[i].seat_id, concorde[i].reserved, concorde[i].first_name, concorde[i].last_name);
                }

                break;
            }
            case 'd': {
                bool is_created = create_reservation(concorde, SEATS);

                if (is_created) {
                    printf("Zarezerwowano. \n");
                } else {
                    printf("Rezerwacja nie powiodla sie. \n");
                }

                break;
            }
            case 'e': {
                bool is_cancelled = cancel_reservation(concorde, SEATS);
                if (is_cancelled) {
                    printf("Usunieto rezerwacje. \n");        
                } else {
                    printf("Rezerwacja nie zostala usunieta. \n");
                }

                break;
            }
        }
    }

    save_data_to_file(concorde, SEATS, RESERVATION_FILE);

    return 0;
}

char menu(void) {
    
    printf("Aby wybrac opcje, wpisz jej oznaczenie literowe: \n");
    printf("a. Pokaz liczbe pustych miejsc \n");
    printf("b. Pokaz liste pustych miejsc \n");
    printf("c. Pokaz alfabetyczna liste miejsc \n");
    printf("d. Zarezerwuj miejsce dla klienta \n");
    printf("e. Usun rezerwacje miejsca \n");
    printf("f. Koniec \n");
    printf(":: ");

    char option = ' ';
    scanf("%c", &option);

    while (getchar() != '\n');

    if (strchr("abcde", option) == NULL) {
        option = 'f';
    }

    return option;
}

void init_data(struct colossus *ptr_fly, int size) {

    for(int i = 0; i < size; i++) {

        ptr_fly[i].seat_id = i;
        ptr_fly[i].reserved = 'F';
        strcpy(ptr_fly[i].first_name, "*******");
        strcpy(ptr_fly[i].last_name, "*******");
    }
}

int count_empty_seats(struct colossus *ptr_fly, int size) {
    
    int empty_seats_counter = 0;
    for (int i = 0; i < size; i++) {

        if (ptr_fly[i].reserved == 'F') {
            empty_seats_counter++;
        }
    }

    return empty_seats_counter;
}

char *list_empty_seats(struct colossus *ptr_fly, int size) {

    char * empty_seats = (char *)malloc(size * sizeof(char));
    if (empty_seats == NULL) {
        fprintf(stderr, "Blad alokacji pamieci. \n");
        return NULL;
    }

    for(int i = 0; i < size; i++) {
        if ((ptr_fly[i].reserved) == 'F') {
            empty_seats[i] = 'O';
        } else {
            empty_seats[i] = 'X';
        }
    }

    return empty_seats;
}

void sort(struct colossus *ptr_fly, int size) {

    for (int i = 0; i < size-1; i++) {

        int max_idx = i;
        for (int j = i+1; j < size; j++) {
            if ((strcmp(ptr_fly[j].last_name, ptr_fly[max_idx].last_name)) >= 0 && ptr_fly[j].reserved == 'T') {
                max_idx = j;
                
            }
        }

        struct colossus swap = ptr_fly[i];
        ptr_fly[i] = ptr_fly[max_idx];
        ptr_fly[max_idx] = swap;
    }
}

bool create_reservation(struct colossus *ptr_fly, int size) {
    
    int seat_id = 0;
    printf("Podaj numer miejsca (0-%d): ", size-1);
    scanf("%d", &seat_id);
    
    while(getchar() != '\n');

    if (seat_id < 0 || seat_id > size-1) {
        return false;
    }

    while(ptr_fly->seat_id != seat_id) {
        ptr_fly++;
    }

    if(ptr_fly->reserved == 'T') {
        return false;
    }

    ptr_fly->reserved = 'T';
    printf("Podaj imie: ");
    fgets(ptr_fly->first_name, TXT_SIZE, stdin);
    printf("Podaj nazwisko: ");
    fgets(ptr_fly->last_name, TXT_SIZE, stdin);

    ptr_fly->first_name[strcspn(ptr_fly->first_name, "\n")] = '\0';
    ptr_fly->last_name[strcspn(ptr_fly->last_name, "\n")] = '\0';

    return true;
}

bool cancel_reservation(struct colossus *ptr_fly, int size) {

    int seat_id = 0;
    printf("Podaj numer miejsca (0-%d): ", size-1);
    scanf("%d", &seat_id);
    
    while(getchar() != '\n');

    if (seat_id < 0 || seat_id > size-1) {
        return false;
    }

    while(ptr_fly->seat_id != seat_id) {
        ptr_fly++;
    }

    if(ptr_fly->reserved == 'F') {
        return false;
    }

    ptr_fly->reserved = 'F';
    strcpy(ptr_fly->first_name, "*******");
    strcpy(ptr_fly->last_name, "*******");

    return true;
}

int load_data_from_file(struct colossus *ptr_fly, int rozmiar, char filename[]) {

    FILE *file = fopen(filename, "r");

    if(file == NULL) {
        fprintf(stderr, "Nie moge otworzyc pliku do odczytu. \n");
        return 1;
    }

    int i = 0;
    while(fscanf(file, "%02d). %c %s %s\n", 
        &ptr_fly[i].seat_id, &ptr_fly[i].reserved, ptr_fly[i].first_name, ptr_fly[i].last_name) == 4) {
            printf("Wczytuje %d \n", ptr_fly[i].seat_id);
            i++;
    }

    fclose(file);

    return 0;
}

int save_data_to_file(struct colossus *ptr_fly, int size, char filename[]) {

    FILE *file = fopen(filename, "w");

    if(file == NULL) {
        fprintf(stderr, "Nie moge otworzyc pliku do zapisu. \n");
        return 2;
    }

    for(int i = 0; i < size; i++) {
        printf("Zapisuje %d \n", ptr_fly[i].seat_id);

        fprintf(file, "%02d). %c %s %s\n", 
            ptr_fly[i].seat_id, ptr_fly[i].reserved, ptr_fly[i].first_name, ptr_fly[i].last_name);
    }

    fclose(file);

    return 0;
}

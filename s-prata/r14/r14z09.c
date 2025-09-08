/*
    r14z09.c: Linie lotnicze Colossus - rozszerzenie programu o cztery rejsy

    9. Linie lotnicze Colossus nabyły drugi samolot (o tej samej liczbie 
    miejsc) i rozszerzyły swoje usługi do czterech rejsów dziennie (rejsy 102, 
    311, 444 i 519). Zmodyfikuj program z poprzedniego ćwiczenia tak, aby 
    obsługiwał on cztery rejsy. Dodaj nadrzędne menu, pozwalające wybrać jeden 
    z lotów lub zakończyć program. Po wybraniu rejsu na ekranie powinno 
    pojawić się menu podobne do tego z ćwiczenia nr 8. Powinno ono jednak 
    zawierać dodatkową opcję: potwierdzenie rezerwacji miejsca. 
    Ponadto, opcja "koniec" powinna zostać zastąpiona opcją 
    "powróć do menu głównego". Przez cały czas na ekranie powinien być widoczny 
    numer lotu, który jest aktualnie modyfikowany. Oprócz tego, lista 
    alfabetyczna (opcja c)) powinna zawierać informację o potwierdzeniu 
    rezerwacji dla każdego z miejsc.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SEATS    12
#define TXT_SIZE 20 + 1
#define FLIGHTS  4
#define FLIGHT_FILE_SIZE FLIGHTS + 11

struct colossus {
    int seat_id;
    char reserved;
    char first_name[TXT_SIZE];
    char last_name[TXT_SIZE];
};

char flight_files[FLIGHTS][FLIGHT_FILE_SIZE] = { 
    "static/102.txt", 
    "static/311.txt", 
    "static/444.txt", 
    "static/519.txt" 
};

char flight_numbers_short[FLIGHTS][4] = { 
    "102", 
    "311", 
    "444", 
    "519" 
};

char main_menu(void);
char menu(const char []);

void init_data(struct colossus *, int);
int count_empty_seats(struct colossus *, int);
char *list_empty_seats(struct colossus *, int);

void sort(struct colossus *, int);

bool create_reservation(struct colossus *, int);
bool cancel_reservation(struct colossus *, int);
bool commit_reservation(struct colossus *, int);

int load_data_from_file(struct colossus *, int, char []);
int save_data_to_file(struct colossus *, int, char []);

int main(void) {

    struct colossus concorde[SEATS];

    init_data(concorde, SEATS);
    char option = ' ';

    while ((option = main_menu()) != 'e') {
        
        char *reservation_file = flight_files[option - '0'];
    
        if(load_data_from_file(concorde, SEATS, reservation_file) != 0) {
            fprintf(stderr, "Blad wczytywania danych z pliku. \n");
            printf("Postaram sie kontynuowac. \n");
            if(save_data_to_file(concorde, SEATS, reservation_file) != 0) {
                fprintf(stderr, "Blad tworzenia pliku. \n");
            } else {
                printf("Utworzono plik z danymi. \n");
                if(load_data_from_file(concorde, SEATS, reservation_file) == 0) {
                    printf("Wczytano dane z pliku. \n");
                } else {
                    fprintf(stderr, "Nadal nie moge wczytac danych z pliku. \n");
                    return 1;
                };
            }
        };

        char *flight_number = flight_numbers_short[option - '0'];
        while ((option = menu(flight_number)) != 'g') {
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
                case 'f': {
                    bool is_commited = commit_reservation(concorde, SEATS);
                    if (is_commited) {
                        printf("Potwierdzono rezerwacje. \n");        
                    } else {
                        printf("Rezerwacja nie zostala potwierdzona. \n");
                    }
                
                    break;
                }
            }
        }

        save_data_to_file(concorde, SEATS, reservation_file);
    }

    return 0;
}

char main_menu(void) {
    
    printf("Wybierz rejs lub zakoncz program: \n");
    printf("0. Rejs 102 \n");
    printf("1. Rejs 311 \n");
    printf("2. Rejs 444 \n");
    printf("3. Rejs 519 \n");
    printf("e. Koniec \n");
    printf(":: ");

    char option = ' ';
    scanf("%c", &option);

    while (getchar() != '\n');

    if (strchr("0123", option) == NULL) {
        option = 'e';
    }

    return option;
}

char menu(const char flight_number[]) {
    
    printf("Rejs %s. \n", flight_number);
    printf("Aby wybrac opcje, wpisz jej oznaczenie literowe: \n");
    printf("a. Pokaz liczbe pustych miejsc \n");
    printf("b. Pokaz liste pustych miejsc \n");
    printf("c. Pokaz alfabetyczna liste miejsc \n");
    printf("d. Zarezerwuj miejsce dla klienta \n");
    printf("e. Usun rezerwacje miejsca \n");
    printf("f. Potwierdz rezerwacje \n");
    printf("g. Powrot do menu glownego \n");
    printf(":: ");

    char option = ' ';
    scanf("%c", &option);

    while (getchar() != '\n');

    if (strchr("abcdef", option) == NULL) {
        option = 'g';
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

    ptr_fly->reserved = 'F';
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

bool commit_reservation(struct colossus *ptr_fly, int size) {

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

    if(ptr_fly->reserved == 'T' || strcmp(ptr_fly->first_name, "*******") == 0) {
        return false;
    }

    ptr_fly->reserved = 'T';

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
        fprintf(file, "%02d). %c %s %s\n", 
            ptr_fly[i].seat_id, ptr_fly[i].reserved, ptr_fly[i].first_name, ptr_fly[i].last_name);
    }

    fclose(file);

    return 0;
}
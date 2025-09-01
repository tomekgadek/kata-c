/*
    r14z04.c: Struktury zagnieżdżone

    4. Napisz program, który tworzy szablon struktury o dwóch składnikach 
    zgodnie z poniższymi kryteriami:

    a. Pierwszym składnikiem jest numer PESEL, a drugim – struktura o trzech 
    składnikach. Jej pierwszy składnik zawiera imię, drugi – drugie 
    imię, a trzeci – nazwisko. Utwórz i zainicjuj tablicę złożoną z trzech 
    takich struktur. Program powinien wyświetlić dane w następującej formie:

    Jordan, Michael J. -- 65092301159

    b. Wyświetlana jest tylko pierwsza litera drugiego imienia wraz z kropką. 
    W przypadku, jeśli składnik zawierający drugie imię jest pusty, program 
    nie powinien wyświetlić ani inicjału (co oczywiste), ani kropki. Algorytm 
    wyświetlania zaimplementuj w postaci oddzielnej funkcji, pobierającej 
    tablicę struktur jako argument.

    c. Zmodyfikuj program opisany w punkcie a. tak, aby funkcja wyświetlająca 
    przyjmowała strukturę, a nie adres tablicy struktur.
*/

#include <stdio.h>
#include <string.h>

#define TXT_SIZE 20 + 1
#define DATABASE_SIZE 3
#define PESEL_SIZE 11 + 1

struct person_data {
    char first_name[TXT_SIZE];
    char second_name[TXT_SIZE];
    char last_name[TXT_SIZE];
};

struct person {
    struct person_data data;
    char pesel[PESEL_SIZE];
};

void print_players(struct person *, int);
void print_player(struct person);

int main(void) {

    struct person nba_players[DATABASE_SIZE] = {
        { { "Michael", "Jeffrey", "Jordan" }, "63092712345" },
        { { "Magic", "", "Johnson" }, "63092754321" },
        { { "Kobe", "Bean", "Bryant" }, "63092767890" }
    };

    print_players(nba_players, DATABASE_SIZE);

    printf("--- \n");

    for (int i = 0; i < DATABASE_SIZE; i++) {
        print_player(nba_players[i]);
    }

    return 0;
}

void print_players(struct person *player, int size) {

    while(size-- > 0) {
        print_player(*player++);
    }
}

void print_player(struct person player) {
    
    printf("%-8s, %-8s %c%c -- %-8s \n", 
        player.data.last_name, 
        player.data.first_name, 
        player.data.second_name[0] != '\0' ? player.data.second_name[0] : ' ', 
        player.data.second_name[0] != '\0' ? '.' : ' ', 
        player.pesel
    );
}

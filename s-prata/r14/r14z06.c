/*
    r14z06.c: Statystyki koszykarzy

    6. Plik tekstowy zawiera informacje o drużynie koszykarskiej. Każdy z jego 
    wierszy ma następujący układ:
    
    ```plaintext
        10 Maciej Zielinski 14 10 8 5
    ```

    Pierwszą pozycją jest numer gracza, należący do przedziału 0–18, drugą – imię 
    gracza, a trzecią – nazwisko. Zarówno imię, jak i nazwisko składają się z 
    jednego słowa. Kolejnymi wartościami są: liczba oddanych rzutów za 2 
    punkty, liczba trafień za 2 punkty, liczba asyst oraz liczba fauli. Plik może 
    zawierać dane z więcej niż jednego meczu, a więc statystyki jednego gracza 
    mogą być zapisane w kilku wierszach, przy czym wiersze te mogą przeplatać 
    się ze statystykami innych graczy.
    
    Napisz program, który pobiera dane z pliku (aż do jego końca) i wczytuje je 
    do tablicy struktur. Każda struktura powinna opisywać jednego gracza i zawierać 
    składniki przeznaczone do przechowania jego imienia, nazwiska, ilości rzutów 
    za 2 punkty, ilości rzutów trafionych, ilości asyst, ilości fauli 
    (chodzi o całkowite ilości ze wszystkich meczów) oraz skuteczności (która 
    zostanie obliczona później). Numer gracza może zostać użyty jako indeks 
    tablicy.

    Najprostszym sposobem, aby to osiągnąć, jest przypisanie wszystkim składnikom 
    struktury wartości 0, wczytywanie danych liczbowych z pliku do zmiennych 
    tymczasowych i dodawanie ich do składników odpowiedniej struktury. Po 
    zakończeniu odczytywania pliku program powinien obliczyć skuteczność każdego 
    gracza i zapisać ją w odpowiednim składniku każdej struktury. Skuteczność 
    otrzymujemy przez podzielenie całkowitej liczby rzutów trafionych przez 
    całkowitą liczbę rzutów oddanych; powinna być ona wartością zmiennoprzecinkową. 
    Program powinien wyświetlić zbiorcze statystyki dla każdego gracza oraz dla 
    całej drużyny.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TXT_SIZE      40 + 1 // full name size
#define PLAYERS_LIMIT 19     // number of players (0..18)

struct basketball_player {

    char full_name[TXT_SIZE];
    float accuracy;
    int shots;
    int successful_shots;
    int assists;
    int fouls;
};

void read_statistics(struct basketball_player *, int, char *);
void show_team(struct basketball_player *, int);
float team_accurancy(struct basketball_player *, int);

int main(void) {

    struct basketball_player players[PLAYERS_LIMIT];

    // init players data
    struct basketball_player empty_player = { '\0', 0.0, 0, 0, 0, 0 };
    for(int i = 0; i < PLAYERS_LIMIT; i++) {
        players[i] = empty_player;
    }

    char filename[] = "static/nba_players_statistics.txt";
    read_statistics(players, PLAYERS_LIMIT, filename);
    show_team(players, PLAYERS_LIMIT);

    float accurancy_for_team = team_accurancy(players, PLAYERS_LIMIT);
    printf("\nSkutecznosc calej druzyny: %.2f. \n", accurancy_for_team);

    return 0;
}

void read_statistics(struct basketball_player *player, int team_size, char *filename) {

    FILE *statistics = fopen(filename, "r");

    if (statistics == NULL) {
        fprintf(stderr, "Nie moge otworzyc pliku %s! \n", filename);
        exit(1);
    }

    int player_number = 0;
    int shots = 0;
    int successful_shots = 0;
    int assists = 0;
    int fouls = 0;

    char first_name[21];
    char last_name[21];

    while(fscanf(statistics, "%d %s %s %d %d %d %d",
        &player_number, first_name, last_name, &shots, &successful_shots, &assists, &fouls) == 7 && 
        player_number < team_size) {

        if(player[player_number].full_name[0] == '\0') {
            strcat(player[player_number].full_name, first_name);
            strcat(player[player_number].full_name, " ");
            strcat(player[player_number].full_name, last_name);
        }

        player[player_number].shots += shots;
        player[player_number].successful_shots += successful_shots;
        player[player_number].assists += assists;
        player[player_number].fouls += fouls;
    }

    fclose(statistics);

    // calculate accuracy for each player
    for(int i = 0; i < team_size; i++) {
        if(player[i].shots > 0) {
            player[i].accuracy = ((float)player[i].successful_shots / (float)player[i].shots);
        }
    }
}

void show_team(struct basketball_player *player, int team_size) {

    printf("Statystylo druzyny NBA: \n");

    for (int i = 0; i < team_size; i++) {
        printf("%d) --- \n", i);
        printf("Zawodnik:    %s \n", player[i].full_name);
        printf("Rzuty:       %d \n", player[i].shots);
        printf("Trafione:    %d \n", player[i].successful_shots);
        printf("Asysty:      %d \n", player[i].assists);
        printf("Faule:       %d \n", player[i].fouls);
        printf("Skutecznosc: %.2f \n", player[i].accuracy);
    }
}


float team_accurancy(struct basketball_player *player, int team_size) {

    int total_shots = 0;
    int total_successful_shots = 0;

    for (int i = 0; i < team_size; i++) {
        total_shots += player[i].shots;
        total_successful_shots += player[i].successful_shots;
    }

    return ((float)total_successful_shots / (float)total_shots);
}

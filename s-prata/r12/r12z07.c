/*
    r12z07.c: Numeracja słów

    7. Zmodyfikuj program z listingu 12.3 tak, aby słowa były ponumerowane 
    według kolejności dodawania ich do listy, poczynając od numeru 1.
    Dopilnuj, aby przy drugim uruchomieniu programu numeracja rozpoczynała
    się od miejsca, w którym została przerwana.
*/

#include <stdio.h>

#define MAX 40

int find_last_number(const char *filename);

int main(void) {

    FILE *wp;
    char slowa[MAX];
    int last_number = find_last_number("slowka.txt");

    if ((wp = fopen("slowka.txt", "a+")) == NULL) {

        fprintf(stdin, "Nie moge otworzyc pliku \"slowka.txt\". \n");
        exit(1);
    }

    puts("Podaj slowa, ktore maja zostac dodane do pliku:");
    puts("Aby zakonczyc, wcisnij Enter na poczatku wiersza.");

    int i = last_number;
    while (gets(slowa) != NULL && slowa[0] != '\0') {
        
        fprintf(wp, "%d. %s ", i, slowa);
        i = i + 1;
    }

    puts("Zawartosc pliku:");
    rewind(wp); /* przejdz do poczatku pliku */

    while (fscanf(wp, "%d. %s", &i, slowa) == 2) {
        printf("%d. %s\n", i, slowa);
    }

    if (fclose(wp) != 0) {
        fprintf(stderr, "Blad przy zamykaniu pliku. \n");
    }

    return 0;
}

int find_last_number(const char *filename) {

    FILE *fp = fopen(filename, "r");

    if (!fp) {
        return 1;
    }

    int num = 0;
    int last_number = 0;
    char word[MAX];

    while (fscanf(fp, "%d. %s", &num, word) == 2) {
        last_number = num;
    }
    
    fclose(fp);

    return last_number + 1;
}

/*
    r14z07.c: Archiwum ksiazek - dodawanie, usuwanie, wyświetlanie i edycja 
    rekordów

    7. Zmodyfikuj listing 14.11 tak, aby w miarę odczytywania kolejnych 
    rekordów i wyświetlania ich na ekranie, możliwe było usunięcie lub zmiana 
    zawartości każdego rekordu. W przypadku usunięcia rekordu w zwolnionym 
    miejscu tablicy powinien zostać umieszczony następny odczytany rekord. Aby 
    umożliwić zmianę zawartości pliku, będziesz musiał użyć trybu "r+b" 
    zamiast "a+b". Będziesz również musiał poświęcić więcej uwagi wskaźnikowi 
    położenia tak, aby dodawane rekordy nie zamazywały rekordów istniejących. 
    Najprostszym wyjściem jest przygotowanie danych w pamięci komputera, a 
    następnie zapisanie ich ostatecznej wersji w pliku.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXTYT 40 + 1
#define MAXAUT 40 + 1
#define MAXKS  5
#define PLIK   "static/books.dat"

struct ksiazka {
    char tytul[MAXTYT];
    char autor[MAXAUT];
    float wartosc;
};

char menu(void);
void wyswietl_ksiazki(struct ksiazka [], int);
int wprowadz_dane(struct ksiazka [], int *, int);
bool edytuj_dane(struct ksiazka [], int, int);
bool usun_dane(struct ksiazka [], int, int *);

int main(void) {

    struct ksiazka biblioteka[MAXKS];
    int rozmiar = sizeof(struct ksiazka);

    FILE *ksiazki = fopen(PLIK, "rb+");

    if (ksiazki == NULL) {
        fprintf(stderr, "Nie moge otworzyc pliku %s. \n", PLIK);
        fprintf(stderr, "Utworz plik, a nastepnie ponownie uruchom program. \n");

        return 1;
    }

    rewind(ksiazki);

    int licznik = 0;
    for( ; licznik < MAXKS && fread(&biblioteka[licznik], rozmiar, 1, ksiazki) == 1; licznik++);

    fclose(ksiazki);

    printf("Odczyt biblioteki ksiazek z pliku %s \n", PLIK);
    printf("Odczytano %d z %d dostepnych rekordow. \n", licznik, MAXKS);

    char opcja;
    while ((opcja = menu()) != 'w') {

        while(getchar() != '\n') {
            continue;
        }

        if (opcja == 'a') {

            wprowadz_dane(biblioteka, &licznik, MAXKS);
            printf("Operacja zakonczona. \n");
        } else if (opcja == 'b') {

            printf("Podaj idx pozycji do edycji: ");
            int idx = -1;
            scanf("%d", &idx);
            while(getchar() != '\n') {
                continue;
            }

            if (edytuj_dane(biblioteka, idx, licznik)) {
                printf("Zapisano. \n");
            }
        } else if (opcja == 'c') {

            printf("Podaj idx pozycji do usuniecia: ");
            int idx = -1;
            scanf("%d", &idx);
            while(getchar() != '\n') {
                continue;
            }

            if (usun_dane(biblioteka, idx, &licznik)) {
                printf("Usunieto. \n");
            }

        } else if (opcja == 'p') {

            wyswietl_ksiazki(biblioteka, licznik);
        }

    }

    ksiazki = fopen(PLIK, "wb");  // czyszczenie pliku
    if (ksiazki == NULL) {
        fprintf(stderr, "Nie moge otworzyc pliku %s. \n", PLIK);
        return 2;
    }

    rewind(ksiazki);
    fwrite(biblioteka, rozmiar, licznik, ksiazki);
    fclose(ksiazki);

    printf("Zapisano %d ksiazek z %d dostepnych pozycji. \n", licznik, MAXKS);
    printf("Dane zapisano do pliku %s. \n", PLIK);

    return 0;
}

char menu(void) {

    printf("\n");
    printf("Operacje na bazie danych spisu ksiazek: \n");
    printf("(a) Wprowadz dane \n");
    printf("(b) Edytuj dane   \n");
    printf("(c) Usun dane     \n");
    printf("(p) Wyswietl dane \n");
    printf("(w) Wyjscie       \n");
    printf(">> ");

    char dostepne_opcje[] = "abcp";
    char znak = ' ';

    scanf("%c", &znak);
    znak = tolower(znak);

    if(strchr(dostepne_opcje, znak) != NULL) {
        return znak;
    }

    return 'w';
}

void wyswietl_ksiazki(struct ksiazka biblioteka[], int rozmiar) {

    printf("Lista ksiazek: \n");

    for (int i = 0; i < rozmiar; i++) {
        printf("[%d] %s, autor: %s, cena: %.2f zl. \n", 
            i, biblioteka[i].tytul, biblioteka[i].autor, biblioteka[i].wartosc);
    }
}

int wprowadz_dane(struct ksiazka biblioteka[], int *licznik, int limit) {

    if (*licznik < limit) {
        printf("Podaj nowe tytuly ksiazek. \n");
        printf("Aby zakonczyc, wcisnij [enter] na poczatku wiersza. \n");
    } else {
        printf("Nie wprowadzisz danych. Plik jest pelny. \n");

        return *licznik;
    }

    char tytul[41];
    printf("Teraz podaj tytul: ");
    while (*licznik < limit && fgets(tytul, 41, stdin) != NULL && tytul[1] != '\0') {
        
        strcpy(biblioteka[*licznik].tytul, tytul);
        biblioteka[*licznik].tytul[strcspn(biblioteka[*licznik].tytul, "\n")] = '\0';
        printf("Teraz podaj autora: ");
        fgets(biblioteka[*licznik].autor, 41, stdin);
        biblioteka[*licznik].autor[strcspn(biblioteka[*licznik].autor, "\n")] = '\0';
        printf("Teraz podaj wartosc: ");
        scanf("%f", &biblioteka[*licznik].wartosc);

        (*licznik)++;

        while (getchar() != '\n') {
            continue;
        }

        if (*licznik < limit) {
            puts("Podaj nastepny tytul: ");
        }
    }

    return *licznik;
}

bool edytuj_dane(struct ksiazka biblioteka[], int idx, int limit) {

    if(idx >= limit || idx < 0) {
        printf("Podana pozycja nie istnieje. \n");
        return false;
    }

    printf("Wprowadz dane dla ksiazki idx = %d. \n", idx);
    printf("Podaj tytul ksiazki: ");
    fgets(biblioteka[idx].tytul, 41, stdin);
    biblioteka[idx].tytul[strcspn(biblioteka[idx].tytul, "\n")] = '\0';
    printf("Teraz podaj autora: ");
    fgets(biblioteka[idx].autor, 41, stdin);
    biblioteka[idx].autor[strcspn(biblioteka[idx].autor, "\n")] = '\0';
    printf("Teraz podaj wartosc: ");
    scanf("%f", &biblioteka[idx].wartosc);

    while (getchar() != '\n') {
        continue;
    }

    return true;
}

bool usun_dane(struct ksiazka biblioteka[], int idx, int *limit) {

    if(idx >= *limit || idx < 0) {
        printf("Podana pozycja nie istnieje. \n");
        return false;
    }

    struct ksiazka pomoc;

    while (idx < (*limit - 1)) {
        pomoc = biblioteka[idx];
        biblioteka[idx] = biblioteka[idx + 1];
        biblioteka[idx + 1] = pomoc;

        idx++;
    }

    (*limit) -= 1;

    return true;
}

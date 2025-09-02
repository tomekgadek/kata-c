/*
    r14z05.c: Średnia ocen studentów

    5. Napisz program, realizujący następujący przepis:

    a. Zdefiniuj zewnętrznie szablon struktury o nazwie daneos, zawierający 
       dwa składniki: łańcuch przechowujący imię i łańcuch przechowujący 
       nazwisko.
    b. Zdefiniuj zewnętrznie szablon struktury o nazwie student, zawierający 
       trzy składniki: strukturę typu daneos, tablicę oceny przechowującą 
       liczby zmiennoprzecinkowe oraz zmienną przechowującą średnią ocen.
    c. W funkcji main() zadeklaruj tablicę złożoną z ROZMIAR 
       (gdzie ROZMIAR = 4) struktur typu student i zainicjalizuj składniki 
       typu daneos przy pomocy dowolnie wybranych imion i nazwisk. Użyj funkcji 
       do wykonania zadań opisanych w punktach d, e, f i g.
    d. Poproś użytkownika o podanie ocen kolejnych studentów i umieść je w 
       składniku oceny odpowiednich struktur. Potrzebna do tego celu pętla może 
       znajdować się – zgodnie z Twoimi preferencjami – w funkcji main() lub w 
       funkcji pobierającej dane.
    e. Oblicz średnią ocen dla każdej struktury i przypisz ją odpowiedniemu 
       składnikowi.
    f. Wyświetl informacje zawarte w każdej ze struktur.
    g. Wyświetl średnią ocen wszystkich studentów.
*/

#include <stdio.h>
#include <string.h>

#define ILE_OCEN      5
#define ROZMIAR_TEXT  20 + 1
#define ROZMIAR       4

struct daneos {
    char imie[ROZMIAR_TEXT];
    char nazwisko[ROZMIAR_TEXT];
};

struct student {
    struct daneos dane;
    float oceny[ILE_OCEN];
    float srednia_ocen;
};

int wprowadz_dane(struct student *, int, int);
float srednia(struct student *, int, int);
void wyswietl_dane(struct student *, int, int);

int main(void) {
    struct student studenci[ROZMIAR];

    int rekordy = wprowadz_dane(studenci, ROZMIAR, ILE_OCEN);
    wyswietl_dane(studenci, rekordy, ILE_OCEN);

    float srednia_calkowita = srednia(studenci, rekordy, ILE_OCEN);
    printf("Srednia ocen wszystkich studentow: %.2f. \n", srednia_calkowita);

    return 0;
}

int wprowadz_dane(struct student *wsk_s, int rozmiar, int ile_ocen) {

    printf("Podaj imie studenta (enter konczy wczytywaie danych): ");

    int licznik = 0;
    while (licznik < rozmiar && 
        fgets(wsk_s->dane.imie, sizeof(wsk_s->dane.imie), stdin) != NULL && 
        wsk_s->dane.imie[1] != '\0') {

        printf("Podaj nazwisko studenta: ");
        fgets(wsk_s->dane.nazwisko, sizeof(wsk_s->dane.nazwisko), stdin);

        wsk_s->dane.imie[strcspn(wsk_s->dane.imie, "\n")] = '\0';
        wsk_s->dane.nazwisko[strcspn(wsk_s->dane.nazwisko, "\n")] = '\0';

        float sum = 0.0;
        for(int i = 0; i < ile_ocen; i++) {
            printf("Podaj %d-ocene studenta: ", i+1);
            scanf("%f", &(wsk_s->oceny[i]));
            sum += wsk_s->oceny[i];
            
        }

        wsk_s->srednia_ocen = sum / ile_ocen;

        while(getchar() != '\n') {
            continue;
        }

        printf("Podaj imie studenta (enter konczy wczytywaie danych): ");
        
        wsk_s++;
        licznik++;
    }

    return licznik;
}

float srednia(struct student *wsk_s, int rozmiar, int ile_ocen) {

    if(rozmiar <= 0 || ile_ocen <= 0) {
        return 0.00;
    }

    float suma_ocen = 0.00;
    for(int i = 0; i < rozmiar; i++) {

        for (int i = 0; i < ile_ocen; i++) {
            suma_ocen += wsk_s->oceny[i];
        }

        wsk_s++;
    }

    float srednia_calkowita = suma_ocen / (rozmiar * ile_ocen);

    return srednia_calkowita;
}

void wyswietl_dane(struct student *wsk_s, int rozmiar, int ile_ocen) {

    for(int i = 0; i < rozmiar; i++) {
        printf("%d) %s, %s \n", i+1, wsk_s->dane.imie, wsk_s->dane.nazwisko);
        printf("Oceny: ");
        for (int i = 0; i < ile_ocen; i++) {
            printf("%-5.2f", wsk_s->oceny[i]);
        }

        printf("\nSrednia = %.2f \n", wsk_s->srednia_ocen);
        printf("--- \n");

        wsk_s++;
    }
}


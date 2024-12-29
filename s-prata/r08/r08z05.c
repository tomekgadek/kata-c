/*
    r08z05.c: Strategia przeszukiwania dwudzielnego

    5. Zmień program z listingu 8.4 tak, aby stosował bardziej inteligentną 
    strategię zgadywania. Na przykład, na początku niech program zapyta 
    użytkownika, czy szukana liczba jest większa, mniejsza czy równa 50. Jeśli 
    szukana liczba jest większa, następna próba powinna być 75, która znajduje 
    się w połowie drogi między 50 a 100. Jeśli 75 jest zbyt duże, kolejną 
    próbą powinna być liczba pomiędzy 75 a 50, i tak dalej. Dzięki opisanej 
    strategii 'przeszukiwania dwudzielnego', program szybko namierza 
    prawidłową odpowiedź, przynajmniej jeśli użytkownik nie oszukuje.
*/

#include <stdio.h>

#define NO  'n'
#define YES 't'

int get_center(int, int);

int main(void) {

    int test_digit = 1;
    char response = NO;

    int left = 1, right = 100, center = 50;

    printf("Wybierz liczbe od 1 do 100. Sprobuje ja zgadnac.");
    printf("\nWpisz \'t\', jesli moja proba jest udana lub");
    printf("\n\'n\', jesli nie trafilem. \n\n");

    while (1) {

        printf("Zgaduje! Czy twoja liczba to %d? (t/n) \n", center);
        scanf("%c", &response);
        fflush(stdin);

        if(response == YES) {
            break;
        }

        printf("No dobrze, czy twoja liczba jest > %d? (t/n) \n", center);
        scanf("%c", &response);
        fflush(stdin);

        if(response == YES) {
            left = center;
            center = get_center(left, right);
            continue;
        }
        
        printf("No dobrze, czy twoja liczba jest < %d? (t/n) \n", center);
        scanf("%c", &response);
        fflush(stdin);
        
        if(response == YES) {
            right = center;
            center = get_center(left, right);
            continue;
        }
    }

    printf("Wiedzialem, ze mi sie uda! \n");

    return 0;
}

int get_center(int left, int right) {

    int diff = right - left;

    if(diff % 2 != 0) {
        diff += 1;
    }

    return left + (diff / 2);
}
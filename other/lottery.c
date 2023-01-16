/*
    Losowanie lotto w jezyku C.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Odpowiada za losowanie unikalnych liczb calkowitych.
 * 
 * @param quantity_result_numbers ilosc wylosowanych liczb.
 * @param quantity_numbers ilosc dostepnych liczb do wylosowania.
 *
 * @return wskaznik do tablicy wylosowanych liczb.
 */
int *lottery(int quantity_result_numbers, int quantity_numbers, int *digits);

/**
 * Weryfikuje czy podana liczba została juz wylosowana.
 * 
 * @param digit szukana liczba.
 * @param size rozmiar tablicy wylosowanych liczb.
 * @param *digits wskaznik do tablicy wylosowanych liczb.
 *
 * @return true - liczba zostala wylosowana, false - liczba nie zostala wylosowana.
 */
bool is_digit_exists(int digit, int size, int *digits);

/**
 * Prezentuje wynik losowania.
 * 
 * @param digits tablica wylosowanych liczb.
 * @param size rozmiar tablicy wylosowanych liczb.
 */
void show_result(int *digits, int size);

/**
 * Alokuje pamiec oraz zwraca utworzony obiekt.
 * 
 * @param size rozmiar tablicy.
 *
 * @return wskaznik do utworzonej tablicy.
 */
int *new(int size);

/**
 * Zwalnia pamiec.
 * 
 * @param *object wskaznik do obiektu.
 */
void delete(int *object);

int main(void) {

    int lottery_digits = 6;
    int all_lottery_digits = 49;

    int *digits = new(lottery_digits);

    int *result = lottery(lottery_digits, all_lottery_digits, digits);
    show_result(result, lottery_digits);

    delete(digits);
    
    return 0;
}

int *lottery(int result_numbers, int quantity_numbers, int *digits) {
    
    if(result_numbers > quantity_numbers) {
        printf("Blad! Liczba kul do wylosowania nie moze byc ");
        printf("wieksza od liczby wszystkich kul dostepnych w losowaniu! \n");

        return NULL;
    }

    srand(time(0));

    int i = 0;
    int digit = 0;
    while(i < result_numbers) {
        digit = rand() % quantity_numbers + 1;

        if(is_digit_exists(digit, result_numbers, digits)) {
            continue;
        }

        digits[i] = digit;
        i = i + 1;
    }

    return digits;
}

bool is_digit_exists(int digit, int size, int *digits) {

    for(int i = 0; i < size; i++) {
        if(digit == digits[i]) {
            return true;
        }
    }

    return false;
}

void show_result(int *digits, int size) {

    for(int i = 0; i < size; i++) {
        printf("%d ", digits[i]);
    }

    printf("\n");
}

int *new(int size) {

    int *object = calloc(size, sizeof(int));
    if(object == NULL) {
        printf("Blad! Wystapil problem z alokacja pamieci! \n");
        exit(0);
    }

    return object;
}

void delete(int *object) {

    if(object != NULL) {
        free(object);
    }
}
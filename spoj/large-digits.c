/*
    large-digits.c: KC015 - Porównywanie dużych liczb

    Zadanie: https://pl.spoj.com/problems/KC015/

    Kompilacja oraz uruchomienie programu: gcc large-digits.c && ./a.out < ./tests/large-digits-tests.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define RELATION_SIZE 3
#define NUMBER_SIZE   1000 + 1

#define N1_EQ_N2 0
#define N1_GT_N2 1
#define N1_LT_N2 -1

bool check_relation(char *, char *, char *);

/*
    return  0, gdy sa takie same (N1_EQ_N2)
    return  1, gdy n1 > n2       (N1_GT_N2)
    return -1, gdy n1 < n2       (N1_LT_N2)
*/
int large_number_cmp(char *, char *);

int main(void) {

    char first_number[NUMBER_SIZE];
    char second_number[NUMBER_SIZE];
    char relation[RELATION_SIZE];

    while(scanf("%s %s %s", first_number, relation, second_number) != EOF) {
        printf("%d \n", check_relation(first_number, relation, second_number));
    }

    return 0;
}

bool check_relation(char *first_number, char *relation, char *second_number) {

    switch(*relation) {
        case '!': return large_number_cmp(first_number, second_number) != 0;
        case '=': return large_number_cmp(first_number, second_number) == 0;
        case '<': return large_number_cmp(first_number, second_number) <= 0;
        case '>': return large_number_cmp(first_number, second_number) >= 0;
    }

    return false;
}

int large_number_cmp(char *first_number, char *second_number) {

    // warunek_1: pierwsza liczba posiada wiecej cyfr
	if(strlen(first_number) > strlen(second_number)){
        return N1_GT_N2;
    }

    // warunek_2: druga liczba posiada wiecej cyfr
    if(strlen(first_number) < strlen(second_number)){ 
        return N1_LT_N2;
    }

    // warunek_3: pierwsza i druga liczba maja taka sama dlugosc
    char first_digit[] = "?"; 
    char second_digit[] = "?";

    while(*first_number && *second_number) {

        first_digit[0] = *first_number;
        second_digit[0] = *second_number;
	
        if(atoi(first_digit) > atoi(second_digit)) {
            return N1_GT_N2;
        } else if(atoi(first_digit) < atoi(second_digit)) {
            return N1_LT_N2; 
        }

        first_number++;
        second_number++;
    }

    return N1_EQ_N2;
}

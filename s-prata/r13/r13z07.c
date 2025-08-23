/*
    r13z07.c: Program do symulacji rzutów wieloma kostkami

    7.** Napisz program, który zachowuje się tak samo, jak modyfikacja listingu 
    13.9, o której wspomnieliśmy po przedstawieniu danych wyjściowych tego 
    listingu. Program powinien wyświetlać następujące dane:

    Podaj liczbę kolejek; wpisz q, aby zakończyć.
    18
    Ile ścian i ile kości?
    6 3
    Oto 18 kolejek rzutów 3 6-ściennymi kostkami.
     12  10   6   9   8  14   8  15   9  14  12  17  11   7  10
     13   8  14
    Ile kolejek? Wpisz q, aby zakończyć.
    q
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(const int, const int);

int main(void) {

    srand((unsigned int) time(0));

    printf("Podaj liczbe kolejek, wpisz q, aby zakonczyc \n");

    int roll_rounds = 0;
    while(scanf("%d", &roll_rounds) == 1 && roll_rounds > 0) {

        printf("Ile scian i ile kosci? \n");
        int dice_sides = 0;
        int dice_count = 0;

        scanf("%d %d", &dice_sides, &dice_count);

        printf("Oto %d kolejek rzutow %d %d-sciennymi kostkami.", roll_rounds, dice_count, dice_sides);

        for(int i = 0; i < roll_rounds; i++) {

            int result = roll_dice(dice_sides, dice_count);

            if(i % 15 == 0) {
                printf("\n ");
            }
                        
            printf("%-4d", result);
        }

        printf("\nIle kolejek? Wpisz q, aby zakonczyc.\n");
    }

    return 0;
}

int roll_dice(const int dice_sides, const int number_of_dice) {

    int result = 0;

    for(int i = 0; i < number_of_dice; i++) {

        result += (rand() % dice_sides + 1);
    }

    return result;
}

/*
    kabbalistic-calendar.c: JZAPKAB - Kabalistyczny zapis daty

    Zadanie: https://www.spoj.com/problems/JZAPKAB/

    Kompilacja oraz uruchomienie programu: gcc kabbalistic-calendar.c && ./a.out < ./tests/kabbalistic-calendar-tests.txt
*/
#include <stdio.h>

#define ALPHABET 23
#define SIZE 2

int main(void) {

    int alphabet[ALPHABET][SIZE] = {
        { 'a', 1   }, { 'b', 2   }, { 'c', 3   }, { 'd', 4   }, { 'e', 5   }, 
        { 'f', 6   }, { 'g', 7   }, { 'h', 8   }, { 'i', 9   }, { 'k', 10  }, 
        { 'l', 20  }, { 'm', 30  }, { 'n', 40  }, { 'o', 50  }, { 'p', 60  }, 
        { 'q', 70  }, { 'r', 80  }, { 's', 90  }, { 't', 100 }, { 'v', 200 }, 
        { 'x', 300 }, { 'y', 400 }, { 'z', 500 },
    };

    int data = 0;

    char sign = '_';
    while((sign = getc(stdin)) != '\n') {
        for(int i = 0; i < ALPHABET; i++ ) {
            if(sign == alphabet[i][0]) {
                data += alphabet[i][1];
            }
        }
    }

    printf("%d \n", data);

    return 0;
}

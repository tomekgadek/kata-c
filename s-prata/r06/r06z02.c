/*
    r06z02.c: Zbuduj trójkąt z dolarów

    2. Użyj pętli zagnieżdżonych, aby uzyskać następujący wzór:

    $
    $$
    $$$
    $$$$
    $$$$$
*/

#include <stdio.h>

const int SIDE = 5;

int main(void) {

    for(int i = 0; i < SIDE; i++) {

        for(int j = 0; j < i + 1; j++) {
            printf("$");
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}

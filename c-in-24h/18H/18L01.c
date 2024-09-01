/* 18L01.c: Definiowanie typow wyliczeniowych */

#include <stdio.h>

/* funkcja main() */
int main(void) {

    enum language {
        human=100,
        animal=50,
        computer
    };

    enum days {
        PON, WTO, SRO, CZW, PIA, SOB, NIE
    };

    printf("human: %d, animal: %d, computer: %d\n", human, animal, computer);
    printf("PON: %d\n", PON);
    printf("WTO: %d\n", WTO);
    printf("SRO: %d\n", SRO);
    printf("CZW: %d\n", CZW);
    printf("PIA: %d\n", PIA);
    printf("SOB: %d\n", SOB);
    printf("NIE: %d\n", NIE);

    return 0;
}

/* 20L02.c: Nakladanie sie elementow unii */

#include <stdio.h>

int main(void) {

    union employee {
        
        int rok;
        int Nr_dzialu;
        int NrID;
    } info;

    /* inicjalizacja elementu: .rok */
    info.rok = 1997;
    /* inicjalizacja elementu: .Nr_dzialu */
    info.Nr_dzialu = 8;
    /* inicjalizacja elementu: .NrID */
    info.NrID = 1234;

    /* wydrukowanie zawartosci unii */
    printf("rok: %d \n", info.rok);
    printf("Nr_dzialu: %d \n", info.Nr_dzialu);
    printf("NrID: %d \n", info.NrID);

    return 0;
}

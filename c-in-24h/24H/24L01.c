/* 24L01.c: Interfejs dla listy ciaglej */

#include <stdio.h>
#include "lnk_list.h"

int main(void) {

    int ch;
    
    printf("Wpisz \na-dodawanie \nd-usuwanie \np-wydruk listy \nq-koniec \n");
    while((ch = getchar()) != 'q') {

        main_interface(ch); /* petla - wywolanie funkcji interfejsu */
    }

    list_node_free();
    printf("\nDo zobaczenia! \n");

    return 0;
}

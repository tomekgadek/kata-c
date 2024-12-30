/*
    r09z02.c: Znak w klumnach od 'i' do 'j'

    2. Zaprojektuj funkcję rzad_zn(ch, i, j), wyświetlającą znak 'ch' w 
    kolumnach od 'i' do 'j'. Wypróbuj ją w prostym programie.
*/

#include <stdio.h>

void rzad_zn(char ch, int i, int j);

int main(void) {

    rzad_zn('#', 5, 9);
    rzad_zn('@', 1, 1);
    rzad_zn('$', 2, 1);
    rzad_zn('!', -2, 1);
    rzad_zn('*', 2, -1);
    rzad_zn('?', -1, -1);

    return 0;
}

void rzad_zn(char ch, int i, int j) {

    if(i > j || i < 0 || j < 0) {

        fprintf(stderr, "!!! incorrect params !!! \n");
        return ;
    }

    for(int counter = 0; counter <= j; counter++) {

        printf("%-3d", counter);
    }

    printf("\n");

    for(int counter = 0; counter <= j; counter++) {

        printf("%-3c", counter >= i ? ch : ' ');
    }

    printf("\n");
}

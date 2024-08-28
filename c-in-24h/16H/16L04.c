/* 16L04.c: Przekazywanie tablicy do funkcji */

#include <stdio.h>

int addThree(int list[]); /* deklaracja funkcji addThree(int list[]); */

int main(void) {

	int suma, lista[3];
	
    printf("Wpisz 3 liczby calkowite: \n");
    scanf("%d%d%d", &lista[0], &lista[1], &lista[2]);
    suma = addThree(lista); /* wywolanie funkcji */
    printf("Suma wynosi: %d\n", suma);

    return 0;
}

int addThree(int list[]) {

    int i;
    int wynik = 0;

    for(i = 0; i < 3; i++) {
        wynik += list[i];
    }

    return wynik;
}

/* 
    r13z01.c: sort.c -- ustawia tablice liczb calkowitych w kolejnosci malejacej
*/

void sort(int tablica[], int granica) {

    int gora, szuk, temp;

    for (gora = 0; gora < granica - 1; gora++) {
        for (szuk = gora + 1; szuk < granica; szuk++) {
            if (tablica[szuk] > tablica[gora]) {
                temp = tablica[szuk];
                tablica[szuk] = tablica[gora];
                tablica[gora] = temp;
            }
        }
    }
}

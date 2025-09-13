/*
    r15z04.c: Program wyznaczający wartość bitu o wskazanym numerze

    4. Napisz funkcję, która przyjmuje dwa argumenty typu int: wartość oraz 
    numer bitu. Funkcja powinna zwracać zawartość bitu o wskazanym numerze.
*/

#include <stdio.h>
#include <assert.h>

int get_bit(int value, int bit_number);

int main(void) {

    assert(get_bit(10, 0) == 0); // najmłodszy bit
    assert(get_bit(10, 1) == 1); // drugi bit
    assert(get_bit(10, 2) == 0); // trzeci bit
    assert(get_bit(10, 3) == 1); // czwarty bit

    printf("Dodatkowy test: 3 bit z liczby 9 (1001) to %d \n", get_bit(9, 3));

    return 0;
}

int get_bit(int value, int bit_number) {
    return (value >> bit_number) & 1;
}

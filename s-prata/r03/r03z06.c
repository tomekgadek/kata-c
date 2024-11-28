/*
    r03z06.c: Oblicz liczbę cząsteczek wody w podanej objętości

    6. Masa jednej cząsteczki wody to około 3.0 × 10⁻²³ g. Litr wody to 1000 g. 
    Napisz program, który pobiera objętość wody w litrach i wyświetla liczbę 
    cząsteczek wody w tej objętości.
*/

#include <stdio.h>

#define WATER_MASS_UNIT     3.0e-23 // g (grams)
#define WATER_DENSITY_GRAMS 1000    // g (grams)

int main(void) {

    double water_in_liters = 0;

    printf("Podaj objetosc wody w litrach: ");
    scanf("%lf", &water_in_liters);
        
    double water_in_grams = water_in_liters * WATER_DENSITY_GRAMS;
    double number_of_water_molecules = water_in_grams / WATER_MASS_UNIT;
    
    printf("W %0.2lf litrach wody miesci sie %e czasteczek. \n", 
        water_in_liters, number_of_water_molecules
    );

    return 0;
}

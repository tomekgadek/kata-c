/*
    r05z04.c: Ile masz gotówki w portfelu?

    4. Zmień program dodaj.c (patrz listing 5.13), obliczający sumę pierwszych 
    20 liczb naturalnych. (Jeśli wolisz, możesz przyjąć, że dodaj.c 
    oblicza, ile pieniędzy otrzymasz w ciągu 20 dni, jeśli pierwszego dnia 
    dostaniesz 1 zł, drugiego – 2 zł, trzeciego – 3 zł, itd.) Zmodyfikuj 
    program tak, abyś mógł w sposób interaktywny określić, jak daleko powinny 
    postępować obliczenia. Innymi słowy, zastąp 20 zmienną pobieraną z 
    klawiatury.
*/

#include <stdio.h>

int main(void) {

    printf("Jak daleko mam sumowac? ");
    
    int limit = 0;
    scanf("%d", &limit);

    int cash = 0, wallet = 0; // PLN
    while(cash++ < limit) {
        wallet += cash;
    }

    printf("Gotowka w portfelu: %d PLN \n", wallet);

    return 0;
}

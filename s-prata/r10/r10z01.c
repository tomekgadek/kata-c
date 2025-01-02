/*
    r10z01.c: Program meteorologiczny

    10. Zmodyfikuj program meteorologiczny z listingu 10.12 tak, aby wykonywał
    on obliczenia korzystając ze wskaźników zamiast indeksów. (Nadal konieczna
    jest deklaracja i inicjalizacja tablicy).
*/

#include <stdio.h>

#define MIESIACE 12
#define LATA      5

int main(void) {

    // inicjalizacja danych z lat 1995 - 1999 o opadach.
    const float deszcz[LATA][MIESIACE] = {
        { 10.2, 8.1, 6.8, 4.2, 2.1, 1.8, 0.2, 0.3, 1.1, 2.3, 6.1, 7.4 },
        {  9.2, 9.8, 4.4, 3.3, 2.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 5.2 },
        {  6.6, 5.5, 3.8, 2.8, 1.6, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 4.2 },
        {  4.3, 4.3, 4.3, 3.0, 2.0, 1.0, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
        {  8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.2 },
    };

    int rok, miesiac;
    float podsuma, suma;
    
    printf(" ROK      OPADY (w cm)\n");
    for(rok = 0, suma = 0; rok < LATA; rok++) {

        for(miesiac = 0, podsuma = 0; miesiac < MIESIACE; miesiac++) {
            podsuma += *(*(deszcz + rok) + miesiac);
        }
        
        printf("%5d %12.1f \n", 1995 + rok, podsuma);
        suma += podsuma;
    }

    printf("Roczna srednia wynosi %.1f cm. \n\n", suma/LATA);
    printf("SREDNIE MIESIECZNE: \n\n");
    printf(" Sty  Lut  Mar  Kwi  Maj  Cze  Lip  Sie  Wrz  Paz ");
    printf(" Lis  Gru \n");
    
    for(miesiac = 0; miesiac < MIESIACE; miesiac++) {

        for(rok = 0, podsuma = 0; rok < LATA; rok++) {
            podsuma += *(*(deszcz + rok) + miesiac);
        }

        printf("%4.1f ", podsuma / LATA);
    }
 
    printf("\n"); 

    return 0;
}

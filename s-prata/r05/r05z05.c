/*
    r05z05.c: Suma kwadratów kolejnych liczb naturalnych

    5. Teraz zmień program tak, aby obliczał sumę kwadratów kolejnych liczb 
    naturalnych. (Lub jak wiele pieniędzy zgromadzisz, otrzymując pierwszego 
    dnia 1 zł, drugiego – 4 zł, trzeciego – 9 zł, itd. Wygląda to 
    na znacznie lepszy interes niż w punkcie 4!) C nie posiada funkcji 
    podnoszącej do kwadratu, ale możesz wykorzystać fakt, iż n^2 
    jest równe n * n.
*/

#include <stdio.h>

int main(void) {

    printf("Jak daleko mam sumowac? ");
    
    int limit = 0;
    scanf("%d", &limit);

    int cash = 0, wallet = 0; // PLN
    while(cash++ < limit) {
        wallet += (cash * cash);
    }

    printf("Gotowka w portfelu: %d PLN \n", wallet);

    return 0;
}
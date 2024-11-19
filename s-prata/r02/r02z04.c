/*
    r02z04.c: Proste wywołania funkcji

    4. Napisz program, dający w wyniku następujący tekst:
    
    Panie Janie!
    Panie Janie!
    Rano wstań!

    Niech program wykorzystuje dwie dodatkowe (poza main()) funkcje: 
    jedną wyświetlającą jednokrotnie tekst Panie Janie! i drugą, 
    wyświetlającą ostatni z podanych wyżej wierszy.
*/

#include <stdio.h>

void alarm1(void);
void alarm2(void);

int main(void) {

    alarm1();
    printf("Panie Janie! \n");
    alarm2();

    return 0;
}

void alarm1(void) {

    printf("Panie Janie! \n");
}

void alarm2(void) {

    printf("Rano wstan! \n");
}

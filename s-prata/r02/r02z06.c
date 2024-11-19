/*
    r02z06.c: Proste wywołania funkcji smile()

    6. Napisz program wyświetlający następujący tekst:
    
    Uśmiech!Uśmiech!Uśmiech!
    Uśmiech!Uśmiech!
    Uśmiech!

    Program powinien definiować funkcję wyświetlającą tekst Uśmiech! 
    jeden raz i wywoływać ją tyle razy, ile jest to potrzebne.
*/

#include <stdio.h>

void smile(void);

int main(void) {

    smile(); smile(); smile();
    printf("\n");
    smile(); smile();
    printf("\n");
    smile();
    printf("\n");

    return 0;
}

void smile(void) {

    printf("Usmiech!");
}

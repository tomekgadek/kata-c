/* 10L03.c: Zagniezdzone instrukcje if */

#include <stdio.h>

int main(void) {

    int i;
    
    for(i = -5; i <= 5; i++) {
        if(i > 0) {
            if(i % 2 == 0) {
                printf("%d to liczba parzysta. \n",i);
            } else {
                printf("%d to liczba nieparzysta. \n",i);
            }
        } else if(i == 0) {
            printf("To jest zero. \n");
        } else {
            printf("Liczba ujemna: %d\n",i);
        }
    }

    return 0;
}

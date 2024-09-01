/* 18L02.c: Zastosowanie wyliczeniowego typu danych */

#include <stdio.h>

int main(void) {

    enum money_units {
        grosik = 1, 
        piatka = 5,
        dycha = 10,
        polowka = 50,
        zlocisz = 100
    };

    int money_units[5] = { zlocisz, polowka, dycha, piatka, grosik };
    char *unit_name[5] = {
        "zlocisz(-ow)",
        "polow(ka/ek)",
        "dycha(-ch)",
        "piatka(-ek)",
        "grosik(-ow)"
    };

    int cent, tmp, i;

    printf("Wpisz sume w groszach:\n");
    scanf("%d", &cent);
    printf("Odpowiada to zestawowi monet:\n");
    tmp = 0;
    for(i = 0; i < 5; i++) {
        tmp = cent / money_units[i];
        cent -= tmp * money_units[i];
        if(tmp)
            printf("%d %s ", tmp, unit_name[i]);
    }
    printf("\n");

    return 0;
}

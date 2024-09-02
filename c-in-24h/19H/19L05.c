/* 19L05.c: Tablica struktur */

#include <stdio.h>

struct wiersz {

    int start_year;
    int end_year;
    char author[16];
    char str1[64];
    char str2[64];
    char str3[64];
};

typedef struct wiersz HK;

void dataDisplay(HK *ptr_s);

int main(void) {

    int i;
    HK poemat[2] = {
        {
            1641,
            1716,
            "MPJ",
            "Wciaz rozmyslasz. Uparcie i skrycie.",
            "Patrzysz w okno i smutek masz w oku.",
            "Przeciez mnie kochasz nad zycie? Sam mowiles przeszlego roku..."
        }, {
            1729,
            1781,
            "WB",
            "Kiedy przyjda podpalic dom,",
            "Ten w ktorym mieszkasz - Polske,",
            "Kiedy rzuca przed siebie grom, kiedy runa zelaznym wojskiem..."
        }
    };

    for(i = 0; i < 2; i++)
        dataDisplay(&poemat[i]);

    return 0;
}

void dataDisplay(HK *ptr_s) {

    printf("%s \n", ptr_s->str1);
    printf("%s \n", ptr_s->str2);
    printf("%s \n", ptr_s->str3);
    printf("--- %s \n", ptr_s->author);
    printf(" (%d-%d) \n\n", ptr_s->start_year, ptr_s->end_year);
}

/*
    r13z09.c: Pobieranie liczb całkowitych z treści pliku

    9. Napisz funkcję, która pobiera i porzuca dane wejściowe aż do momentu 
    odczytania cyfry, następnie zapisuje tę cyfrę i wszystkie kolejne aż do 
    napotkania znaku nie będącego cyfrą. Znak nienumeryczny zostaje umieszczony 
    z powrotem w strumieniu wejściowym, a funkcja przetwarza ciąg cyfr na 
    wartość liczbową. Wartość ta powinna zostać dostarczona funkcji wywołującej 
    za pośrednictwem argumentu wskaźnikowego. Funkcja powinna zwracać EOF w 
    przypadku napotkania końca pliku lub 1 w pozostałych przypadkach. 
    Skorzystaj z funkcji getc() i ungetc(). Mówiąc w skrócie, funkcja powinna 
    znaleźć najbliższą liczbę całkowitą w danych wejściowych, niezależnie od 
    tego, czy występuje ona samodzielnie, czy jest otoczona tekstem 
    (np. w7niebie).
*/

#include <stdio.h>
#include <ctype.h>

int char_to_int(const char);
int find_digits(FILE *, int *);

int main(void) {

    char filename[] = "static/digits.txt";

    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        return -1;
    }

    for(int digit = 0; find_digits(file, &digit) == 1; ) {
        printf("Znaleziono liczbe: %d \n", digit);
    }

    fclose(file);

    return 0;
}

int char_to_int(const char sign) {

    return isdigit(sign) ? sign - '0' : -1;
}

int find_digits(FILE *file, int *digit) {

    char sign;
    while((sign = getc(file)) != EOF) {

        if(!isdigit(sign)) {
            continue;
        }

        int value = 0;
        do {
            value = value * 10 + char_to_int(sign);
            sign = getc(file);
        } while(isdigit(sign));

        if(sign != EOF) {
            ungetc(sign, file);
        }

        *digit = value;

        return 1;
    }

    return EOF;
}

/*
    r13z10.c: Pobieranie liczb całkowitych (z uwzględnieniem znaku) z treści 
    pliku

    10. Zmodyfikuj funkcję z poprzedniego ćwiczenia tak, aby rozpoznawała 
    ona znak minus. (W przypadku wpisania tekstu w-7niebie powinna ona uzyskać 
    wartość -7.)
*/

#include <stdio.h>
#include <ctype.h>

#define SIGN_POSITIVE +1
#define SIGN_NEGATIVE -1

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

    int number_sign = SIGN_POSITIVE;

    char sign;
    while((sign = getc(file)) != EOF) {

        if(sign == '-') {
            number_sign = SIGN_NEGATIVE;
        }

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

        *digit = (value * number_sign);

        return 1;
    }

    return EOF;
}

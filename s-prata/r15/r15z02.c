/*
    r15z02.c: Operacje na łańcuchach binarnych

    2. Napisz program, który pobiera dwa łańcuchy binarne z wiersza poleceń, a 
    następnie wyświetla efekt zastosowania do każdego z nich operatora `~` oraz 
    połączenia ich za pomocą operatorów `&`, | i `^`. Wartości wynikowe powinny 
    zostać wyświetlone jako łańcuchy binarne.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *not(const char *);
char *xor(const char *, const char *);
char *and(const char *, const char *);
char *or(const char *, const char *);

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Użycie: %s <bin1> <bin2> \n", argv[0]);
        return 1;
    }

    char *bin_first = argv[1];
    char *bin_second = argv[2];

    if(strlen(bin_first) != strlen(bin_second)) {
        printf("Lancuchy musza miec taka sama dlugosc. \n");
        return 1;
    }

    if(strspn(bin_first, "01") != strlen(bin_first) || strspn(bin_second, "01") != strlen(bin_second)) {
        printf("Lancuchy musza byc binarne (zawierac tylko 0 i 1). \n");
        return 1;
    }

    char *not_result_first = not(bin_first);
    char *not_result_second = not(bin_second);

    printf("~(%s) = %s \n", bin_first, not_result_first);
    printf("~(%s) = %s \n", bin_second, not_result_second);
    free(not_result_first);
    free(not_result_second);

    char *xor_result = xor(bin_first, bin_second);

    printf("%s ^ %s = %s \n", bin_first, bin_second, xor_result);
    free(xor_result);

    char *and_result = and(bin_first, bin_second);

    printf("%s & %s = %s \n", bin_first, bin_second, and_result);
    free(and_result);

    char *or_result = or(bin_first, bin_second);

    printf("%s | %s = %s \n", bin_first, bin_second, or_result);
    free(or_result);

    return 0;
}

char *not(const char *bin) {

    size_t size = strlen(bin);
    char *result = malloc(size + 1);

    if(result == NULL) {
        return NULL;
    }

    for(int i = 0; i < size; i++) {
        result[i] = (bin[i] == '0') ? '1' : '0';
    }

    result[size] = '\0';

    return result;
}

char *xor(const char *bin_f, const char *bin_s) {

    size_t size = strlen(bin_f);
    char *result = malloc(size + 1);

    if(result == NULL) {
        return NULL;
    }

    for(int i = 0; i < size; i++) {
        result[i] = (bin_f[i] != bin_s[i]) ? '1' : '0';
    }

    result[size] = '\0';

    return result;
}

char *and(const char *bin_f, const char *bin_s) {

    size_t size = strlen(bin_f);
    char *result = malloc(size + 1);

    if(result == NULL) {
        return NULL;
    }

    for(int i = 0; i < size; i++) {
        result[i] = (bin_f[i] == '1' && bin_s[i] == '1') ? '1' : '0';
    }

    result[size] = '\0';

    return result;
}

char *or(const char *bin_f, const char *bin_s) {

    size_t size = strlen(bin_f);
    char *result = malloc(size + 1);

    if(result == NULL) {
        return NULL;
    }

    for(int i = 0; i < size; i++) {
        result[i] = (bin_f[i] == '1' || bin_s[i] == '1') ? '1' : '0';
    }

    result[size] = '\0';

    return result;
}
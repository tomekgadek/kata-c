/* 13L02.c: Pomiar dlugosci lancuchow tekstowych */

#include <stdio.h>
#include <string.h>

int main(void) {

    char str1[] = {
        'A',' ',
        's', 't', 'r', 'i', 'n', 'g',' ',
        'c', 'o', 'n', 's', 't', 'a', 'n', 't', '\0'
    };

    char str2[] = "Another string constant";
    char *ptr_str = "Assign a string to pointer";

    printf("Dlugosc str1 wynosi: %lu bajow\n", strlen(str1));
    printf("Dlugosc str2 wynosi: %lu bajty\n", strlen(str2));
    printf("Dlugosc lancucha przypisanego wskaznikowi ptr_str to: %lu bajtow\n", strlen(ptr_str));

    return 0;
}

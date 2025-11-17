#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "caesar.h"

char * encode(char input[], int key) {

    if(key < 0) {
        fprintf(stderr, "key < 0! \n");
        exit(123);
    }

    int letters = 26;
    int sign_shift = key % letters;

    int data_size = strlen(input);
    char * output = (char *)malloc(data_size + 1);

    if(output == NULL) {
        printf("Blad alokacji pamieci (funkcja encode())! \n");
        exit(2);
    }

    int i = 0;
    for(char ch = '?'; (ch = input[i]) != '\0'; i++) {

        if(ch >= 'A' && ch <= 'Z') {

            ch = 'A' + (ch - 'A' + sign_shift) % letters;
        }

        output[i] = ch;
    }

    output[data_size] = '\0';

    return output;
}

char * decode(char input[], int key) {

    if(key < 0) {
        fprintf(stderr, "key < 0! \n");
        exit(123);
    }

    int letters = 26;
    int sign_shift = key % letters;

    int data_size = strlen(input);
    char * output = (char *)malloc(data_size + 1);

    if(output == NULL) {
        printf("Blad alokacji pamieci (funkcja encode())! \n");
        exit(2);
    }

    int i = 0;
    for(char ch = '?'; (ch = input[i]) != '\0'; i++) {

        if(ch >= 'A' && ch <= 'Z') {

            ch = 'A' + (ch - 'A' - sign_shift + letters) % letters;
        }

        output[i] = ch;
    }

    output[data_size] = '\0';

    return output;
}

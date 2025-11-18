#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fence.h"

fen_t * create_fence(int data_size, int key) {

    if(key < 2) {
        fprintf(stderr, "key < 2! \n");
        exit(123);
    }

    fen_t * fence = (fen_t *)malloc(data_size * sizeof(fen_t));

    if(fence == NULL) {
        printf("Blad alokacji pamieci (funkcja build_fence())! \n");
        exit(1);
    }

    int change_sign = -1;

    int fence_key = 0;
    for(int i = 0; i < data_size; i++) {

        if(fence_key == 0 || fence_key == key - 1) {
            change_sign *= -1;
        }

        fence->level = fence_key;
        fence->letter = ' ';
        fence++;

        fence_key += change_sign;
    }

    fence -= data_size;

    return fence;
}

char * encode(char input[], fen_t fen[], int key) {

    if(key < 2) {
        fprintf(stderr, "key < 2! \n");
        exit(123);
    }

    int data_size = strlen(input);
    char * output = (char *)malloc(data_size + 1);

    if(output == NULL) {
        printf("Blad alokacji pamieci (funkcja encode())! \n");
        exit(2);
    }

    for(int i = 0; i < data_size; i++) {

        fen[i].letter = input[i];
    }

    int message_idx = 0;
    for(int level = 0; level < key; level++) {

        for(int f = 0; f < data_size; f++) {

            if(fen[f].level == level) {
                output[message_idx] = fen[f].letter;
                message_idx++;
            }
        }
    }

    output[message_idx] = '\0';

    return &output[0];
}

char * decode(char input[], fen_t fen[], int key) {

    int data_size = strlen(input);
    char * output = (char *)malloc(data_size + 1);

    if(key < 2) {
        fprintf(stderr, "key < 2! \n");
        exit(123);
    }

    int message_idx = 0;
    for(int level = 0; level < key; level++) {

        for(int f = 0; f < data_size; f++) {

            if(fen[f].level == level) {
                fen[f].letter = input[message_idx];
                message_idx++;
            }
        }
    }

    for(int i = 0; i < data_size; i++) {

        output[i] = fen[i].letter;
    }

    output[data_size] = '\0';

    return &output[0];    
}

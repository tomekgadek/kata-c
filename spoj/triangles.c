/*
    triangles.c: RODZ_TRO - Rodzaje trójkątów

    Zadanie: https://pl.spoj.com/problems/RODZ_TRO/

    Kompilacja oraz uruchomienie programu: gcc triangles.c && ./a.out < ./tests/triangles-tests.txt
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define SIDES 3

const char *types_of_rectangles[] = {
    "brak", "ostrokatny", "prostokatny", "rozwartokatny", 
};

bool is_triangle(int[]);
void move_max_to_end(int[]);

int main(void) {

    int triangle[SIDES] = { 0, 0, 0 };

    while(scanf("%d %d %d", &triangle[0], &triangle[1], &triangle[2]) != EOF) {

        if(!is_triangle(triangle)) {
            printf("%s \n", types_of_rectangles[0]);
            continue;
        }

        move_max_to_end(triangle);

        int a2 = pow(triangle[0], 2); // a^2
        int b2 = pow(triangle[1], 2); // b^2
        int c2 = pow(triangle[2], 2); // c^2

        // Twierdzenie odwrotne do twierdzenia Pitagorasa
        if(a2 + b2 == c2) {		
            printf("%s \n", types_of_rectangles[2]);
        } else if(a2 + b2 > c2) {
            printf("%s \n", types_of_rectangles[1]);
        } else if(a2 + b2 < c2) {
            printf("%s \n", types_of_rectangles[3]);
        }
    }

    return 0;
}

bool is_triangle(int triangle[]) {

    int idx[3][3] = {{ 0, 1, 2 }, { 2, 0, 1 }, { 1, 2, 0 }};

    bool can_create = false;
    for(int i = 0; i < 3; i++) {
        can_create = (triangle[idx[i][0]] + triangle[idx[i][1]] > triangle[idx[i][2]]);
        if(!can_create) {
            return false;
        }
    }

    return true;
}

void move_max_to_end(int triangle[]) {

    int max = triangle[0];
    int max_idx = 0;

    for(int i = 1; i < 3; i++) {
        if(max < triangle[i]) {
            max = triangle[i];
            max_idx = i;
        }
    }

    if(max_idx != 2) {
        int swap = triangle[2];
        triangle[2] = max;
        triangle[max_idx] = swap;
    }
}
/*
    marker.c: FLAMASTE - Flamaster

    Zadanie: https://pl.spoj.com/problems/FLAMASTE/

    Kompilacja oraz uruchomienie programu: gcc marker.c && ./a.out < ./tests/marker-tests.txt
*/
#include <stdio.h>

#define LINE_SIZE    201
#define MARKER_LIMIT 2

int main(void) {

    char text_line[LINE_SIZE];
    int how_many_lines = 0;

    scanf("%d", &how_many_lines);

    for(int i = 0 ; how_many_lines > 0; how_many_lines--) {

        scanf("%s", text_line);

        i = 0;
        while(text_line[i] != '\0') {

            char main_sign = text_line[i];
            putchar(main_sign);

            int similar_signs = 0;
            for( ; text_line[i] == main_sign; i++, similar_signs++);

            if(similar_signs > MARKER_LIMIT) {

                printf("%d", similar_signs);
            }
            
            if(similar_signs == MARKER_LIMIT) {

                printf("%c", main_sign);
            }
        }

        putchar('\n');
    }

    return 0;
}

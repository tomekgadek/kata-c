/*
    avg.c: PP0604A - Średnia arytmetyczna

    Zadanie: https://pl.spoj.com/problems/PP0604A/

    Kompilacja oraz uruchomienie programu: gcc avg.c && ./a.out < ./tests/avg-tests.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct stats_t {

    int *numbers;
    int size_numbers;
    float average;
};

struct stats_t * insert_data(struct stats_t *);
struct stats_t * calculate_average(struct stats_t *);
int get_nearest_to_average(struct stats_t *);
void clear_stats(struct stats_t *);

int main(void) {

    int how_many_tests = 0;
    struct stats_t stats = { NULL, 0, 0.0 };
    struct stats_t * p_stats = &stats;

    scanf("%d", &how_many_tests);

    while(how_many_tests-- > 0) {

        scanf("%d", &stats.size_numbers);

        p_stats = insert_data(&stats);

        if(p_stats == NULL) {
            return 1;
        }

        calculate_average(p_stats);
        int digit = get_nearest_to_average(p_stats);

        printf("%d \n", digit);

        free(p_stats->numbers);

        clear_stats(p_stats);
    }

    return 0;
}

struct stats_t * insert_data(struct stats_t *p_stats) {

    p_stats->numbers = calloc(p_stats->size_numbers, sizeof(struct stats_t));

    if(p_stats->numbers == NULL) {
        return NULL;
    }

    for(int i = 0; i < p_stats->size_numbers; i++) {
        scanf("%d", &p_stats->numbers[i]);
    }

    return p_stats;
}

struct stats_t * calculate_average(struct stats_t *p_stats) {

    for(int i = 0; i < p_stats->size_numbers; i++) {
        p_stats->average += (float) p_stats->numbers[i];
    }

    p_stats->average /= (float) p_stats->size_numbers;

    return p_stats;
}

int get_nearest_to_average(struct stats_t *p_stats) {

    float min_difference = fabs(p_stats->numbers[0] - p_stats->average);
    int nearest_digit_to_avg = p_stats->numbers[0];

    float diff = 0.0;

    for(int i = 1; i < p_stats->size_numbers; i++) {

        diff = fabs(p_stats->numbers[i] - p_stats->average);

        if(diff < min_difference) {
            min_difference = diff;
            nearest_digit_to_avg = p_stats->numbers[i];
        }
    }

    return nearest_digit_to_avg;
}

void clear_stats(struct stats_t *p_stats) {
    p_stats->numbers = NULL;
    p_stats->size_numbers = 0;
    p_stats->average = 0.0;
}

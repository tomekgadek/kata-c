/*
    hist.c: PASTAB4 - Histogram z liczb

    Zadanie: https://pl.spoj.com/problems/PASTAB4/

    Kompilacja oraz uruchomienie programu: gcc hist.c && ./a.out < ./tests/hist-tests.txt
*/
#include <stdio.h>
#include <math.h>

#define DIAGRAM_WIDTH 30
#define DATA_SIZE     21 // <-10, 10>

typedef struct histogram_t {

    int data[DATA_SIZE];
    int data_size;
    int width;
    int max_value;
} hist_t;

hist_t * prepare_hist(hist_t *);
int get_max(int [], int);
void show_hist(hist_t *);
void display_stars_in_line(int, int, int);

int main(void) {

    hist_t histogram = { {}, DATA_SIZE, DIAGRAM_WIDTH, 0 };
	
    for(int i = 0; i < histogram.data_size; i++) {
        histogram.data[i] = 0;
    }

    prepare_hist(&histogram);
    histogram.max_value = get_max(histogram.data, histogram.data_size);

    if(histogram.max_value > 0) {
        show_hist(&histogram);
    }

    return 0;
}

hist_t * prepare_hist(hist_t * hist_ptr) {

    int shift = 10; // dopasowanie histgramu do tablicy: tablica <0, 20>, histogram <-10, 10>.

	int digit = 0;
    while(fscanf(stdin, "%d", &digit) != EOF) {
        hist_ptr->data[digit + shift]++;
    }

    return hist_ptr;
}

int get_max(int data[], int size) {

    int max_value = 0;

    for(int i = 0; i < size; i++) {
        if(max_value < data[i]) {
            max_value = data[i];
        }
    }

    return max_value;
}

void show_hist(hist_t * hist_ptr) {
	
    for(int i = 0, j = -10; i < hist_ptr->data_size; i++, j++) {

		int quantity_stars = (int)round((double)hist_ptr->width * hist_ptr->data[i] / (double)hist_ptr->max_value);
		display_stars_in_line(j, hist_ptr->width, quantity_stars);
	}
}

void display_stars_in_line(int line_number, int width, int quantity_stars) {

    printf("%3d:|", line_number);

    for(int h = 0; h < width; h++) {

        if(h < quantity_stars) {
            printf("*");
        } else {
            printf(" ");
        }
    }

	printf("|\n");
}

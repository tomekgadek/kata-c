/*
	sort-points.c: PP0506A - Sort 1

	Zadanie: https://pl.spoj.com/problems/PP0506A/

	Kompilacja oraz uruchomienie programu: gcc sort-points.c && ./a.out < ./tests/sort-points-tests.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define POINT_NAME_SIZE 10 + 1

typedef struct point_t {

	char name[POINT_NAME_SIZE];
	short x;
	short y;
	double distance;
} pt_t;

double calculate_distance(int x1, int y1, int x0, int y0);
pt_t * sort_points(pt_t *, int);
void print_points(pt_t *, int);

int main(void) {

	int how_many_tests = 0;
	scanf("%d", &how_many_tests);

	while(how_many_tests-- > 0) {

		int how_many_points = 0;
		scanf("%d", &how_many_points);

		pt_t * points = (pt_t *)malloc(how_many_points * sizeof(pt_t));

		if(points == NULL) {
			exit(1);
		}

		// insert points
		for(int i = 0; i < how_many_points; i++) {
			scanf("%s %hd %hd", points[i].name, &points[i].x, &points[i].y);
			points[i].distance = calculate_distance(points[i].x, points[i].y, 0, 0);
		}
	
		sort_points(points, how_many_points);
		print_points(points, how_many_points);

		free(points);
	}

	return 0;
}

double calculate_distance(int x1, int y1, int x0, int y0) {

	return (double)sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
}

/* 
	Sortowanie babelkowe :)
	Oczywiscie, ze to nieoptymalne rozwiazanie :))
*/
pt_t * sort_points(pt_t * points, int points_size) {

	for(int i = 0; i < points_size; i++) {

		for(int j = 0; j < points_size-1-i; j++) {

			if(points[j].distance >= points[j+1].distance) {

				pt_t swap = points[j];
				points[j] = points[j+1];
				points[j+1] = swap;
			}
		}
	}

	return points;
}

void print_points(pt_t * points, int points_size) {

	for(int i = 0; i < points_size; i++) {
		printf("%s %hd %hd \n", points[i].name, points[i].x, points[i].y);
	}

	printf("\n");
}

/*
    Program, ktory weryfikuje, jak dlugo trwa algorytm.
*/

#include <stdio.h>
#include <time.h>

/**
 * Odpowiada za wyprowadzenie informacji o czasie trwania algorytmu.
 *
 * @param (*fun)() wskaznik do funkcji bezparametrowej
 *
 */
void algorithm_duration(void (*fun)());

/**
 * Testowa metoda.
 */
void test();

int main(void) {

    algorithm_duration(test);

    return 0;
}

void algorithm_duration(void (*fun)()) {

    clock_t start, stop;
    double duration;

    start = clock();

	(*fun)();   // wywolanie funkcji

	stop = clock();
	duration = (double)(stop - start) / CLOCKS_PER_SEC;

	printf("Czas wykonywania programu %2.2lf sek.\n", duration);
}

void test() {

    for(int i = 0; i < 200000000; i++);
}
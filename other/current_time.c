/*
	Program, który wyprowadza na wyjście aktualną datę i czas.
*/

#include <stdio.h>
#include <time.h>

int main(void) {

    time_t now;
    time(&now);

    printf("Current date and time: %s", asctime(localtime(&now)));

    return 0;
}

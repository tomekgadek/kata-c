#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {

	struct Stack stack;
	initStack(&stack); // Inicjalizacja stosu

	push(&stack, 5);
	push(&stack, 10);
	push(&stack, 15);

	printf("Popped: %d\n", pop(&stack));
	printf("Popped: %d\n", pop(&stack));
	printf("Popped: %d\n", pop(&stack));
	printf("Popped: %d\n", pop(&stack));

	return 0;
}

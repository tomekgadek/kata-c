/*
	Implementacja stosu przy pomocy dynamicznych struktur danych.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void initStack(struct Stack * stack) {
	stack->top = NULL;
}

bool isEmpty(struct Stack * stack) {
	return stack->top == NULL;
}

void push(struct Stack *stack, int value) {
	struct StackNode * newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
	if (newNode == NULL) {
		printf("Problem z alokacja pamieci! \n");
		return ;
	}

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack *stack) {
	if (isEmpty(stack)) {
		printf("Stos jest pusty! Nie moge pobrac danych! \n");
		return 0;
	}

	int poppedValue = stack->top->data;
    struct StackNode * node = stack->top;
    stack->top = stack->top->next;

    free(node);

    return poppedValue;
}

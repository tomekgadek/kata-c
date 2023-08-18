#ifndef STACK_H
#define STACK_H

/**
 * Struktura reprezentująca węzeł stosu.
 */
struct StackNode {
    int data;               /**< Dane przechowywane w węźle. */
    struct StackNode *next; /**< Wskaźnik do następnego węzła. */
};

/**
 * Struktura reprezentująca stos.
 */
struct Stack {
    struct StackNode *top; /**< Wskaźnik do wierzchołka stosu. */
};

/**
 * Inicjalizuje stos, ustawiając wskaźnik wierzchołka na NULL.
 *
 * @param stack Wskaźnik do struktury reprezentującej stos.
 */
void initStack(struct Stack *stack);

/**
 * Sprawdza, czy stos jest pusty.
 *
 * @param stack Wskaźnik do struktury reprezentującej stos.
 * @return true, jeśli stos jest pusty, w przeciwnym razie false.
 */
bool isEmpty(struct Stack *stack);

/**
 * Dodaje wartość na szczyt stosu.
 *
 * @param stack Wskaźnik do struktury reprezentującej stos.
 * @param value Wartość do dodania na szczyt stosu.
 */
void push(struct Stack *stack, int value);

/**
 * Usuwa i zwraca wartość ze szczytu stosu.
 *
 * @param stack Wskaźnik do struktury reprezentującej stos.
 * @return Wartość ze szczytu stosu.
 */
int pop(struct Stack *stack);


#endif

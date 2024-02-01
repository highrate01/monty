#include "monty.h"

/**
 * free_stack - free a doubly linked list
 * @head: pointer to the first node
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *aux;

	aux = stack;
	while (stack != NULL)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
}



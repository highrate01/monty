#include "monty.h"

/**
 * pall_func - prints the stack
 * @stack: double pointer to first element on stack
 * @line_number: line number
 * Return: no return
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void) line_number;

	h = *stack;
	if (h == NULL)
		return;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

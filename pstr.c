#include "monty.h"

/**
 * pstr_func - prints string at the top of stack
 *
 * @stack: double pointer to the stack
 * @line_number: line number
 * Return: nothin
 */
void pstr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void) line_number;

	h = *stack;
	while (h != NULL)
	{
		if (h->n > 127 || h->n <= 0)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

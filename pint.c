#include "monty.h"

/**
 * pint_func - prints the value at the top of the stack,
 * followed by a new line
 * @stack: double pointer to first element
 * @line_number: line number
 * Return: no return
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

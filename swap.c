#include "monty.h"

/**
 * swap_func - swaps the top two elements of the stack
 * @stack: double pointe to the stack
 * @line_number: line number
 * Return: no return
 */

void swap_func(stack_t **stack, unsigned int line_number)
{
	int len;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	len = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = len;
}

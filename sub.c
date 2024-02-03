#include "monty.h"

/**
 * sub_func - subtracts the top element of the stack from the second
 * top element of the stack
 * @stack: double pointer tostack
 * @line_number: line number
 * Return: nothing
 */
void sub_func(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop_func(stack, line_number);
}

#include "monty.h"

/**
 * mull_func - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 * Return: nothing
 */

void mul_func(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop_func(stack, line_number);
}

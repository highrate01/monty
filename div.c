#include "monty.h"

/**
 * div_func - divides the top two elements of the stack
 *
 * @stack: doubly pointer to the stack
 * @line_number: line number
 * Return: no return
 */
void div_func(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.len < 2)
	{
		dprintf(STDOUT_FILENO, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop_func(stack, line_number);
	if (n == 0)
	{
		dprintf(STDOUT_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n /= n;
}

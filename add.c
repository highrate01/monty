#include "monty.h"

/**
 * add_func - add the  elemnt of the stack
 * @stack: double pointer to the first node
 * @line_number: line number
 * Description: it aadd the top two element of the stack
 * Return: no return
 */
void add_func(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop_func(stack, line_number);
}

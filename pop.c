#include "monty.h"
/**
 * pop_func -to delete from the stack
 *
 * @stack: double pointer to the first node on the
 * stack
 * @line_number: line number
 */
void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: Can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

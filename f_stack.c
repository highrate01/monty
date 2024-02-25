#include "monty.h"

/**
 * free_stack - free stack
 *
 * @stack: pointer to the first node
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
/**
 * inti_stack - initialise stack
 *
 * @stack: pointer to first node
 * Return: 1 on success, 0 therwise
 */
int inti_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));

	if (s == NULL)
		return (malloc_error());
	s->n = STACK;
	s->prev = NULL;
	*stack = s;
	return (EXIT_SUCCESS);
}
/**
 * check_mode - check if stack linkred list is in
 * STACK or QUEUE mode
 * @stack: pointer
 * Return: int
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
	{
		return (STACK);
	}
	else if (stack->n == QUEUE)
		return (QUEUE);
	return 2;
}

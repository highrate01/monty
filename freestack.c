#include "monty.h"

/**
 * free_stack - free a doubly linked list
 * @head: pointer to the first node
 * @current: exit
 * Return: nothing
 */
void free_stack(int current, void *head)
{
	stack_t **stack;
	stack_t *next;
	(void) current;

	stack = (stack_t **)head;
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	var.len = 0;
}



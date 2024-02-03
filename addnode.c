#include "monty.h"

/**
 * add_node - add node to stack
 *
 * @stack: double pointer to the stack
 * @n: new node
 * Return: no return
 */
stack_t *add_node(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		(*stack)->prev->next = new_node;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	if (var.queue == STACK || var.len == 0)
		*stack = new_node;
	return (new_node);
}

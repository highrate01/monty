#include "monty.h"

/**
 * add_node - add node to the othe side of stack
 * @n: new node
 * @stack: double pointer to the first node
 * Description: The func will add new node to the begining
 *  and end of queue list.
 * Return: pointer to the new node or null on failure
 */
void *add_node(stack_t **stack, const int n)
{
	stack_t *new_node, *aux;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
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

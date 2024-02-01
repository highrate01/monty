#include "monty.h"

/**
 * queue_func - print the top of the stack
 *
 * @head: double pointer to the first node of the stack
 * @line_number: line_number
 * Return: no return
 *
void queue_func(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int global = 1;
	(void)stack;
	(void)line_number;
}*/

/**
 * add_queue - add node to the othe side of stack
 * @n: new node
 * @stack: double pointer to the first node
 * Return: no return
 */
void add_queue(stack_t **stack, int n)
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
		*stack = new_node;
		new_node->prev = NULL;
		return;
	}
	aux = *stack;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new_node;
	new_node->prev = aux;
}

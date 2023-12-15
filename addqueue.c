#include "monty.h"

/**
 * queue_func - print the top of the stack
 *
 * @head: double pointer to the first node of the stack
 * @count: line_number
 * Return: no return
 */
void queue_func(stack_t **head, __attribute__((unused))unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 1;
}

/**
 * add_queue - add node to the othe side of stack
 * @n: new node
 * @head: double pointer to the first node
 * Return: no return
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;

	if (aux != NULL)
	{
		while (aux->next != NULL)
			aux = aux->next;
	}

	if (aux == NULL)
	{
		*head = new_node;
		new_node->prev = aux;
	}
}

#include "monty.h"

/**
 * free_stack - free a doubly linked list
 * @head: pointer to the first node
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head != NULL)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}



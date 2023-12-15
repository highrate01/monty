#include "monty.h"

/**
 * sub_func - subtracts the top element of the stack from the second
 * top element of the stack
 * @head: double pointer tostack
 * @counter: line number
 * Return: nothing
 */
void sub_func(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int subt, nodes;

	aux = *head;
	nodes = 0;
	while (aux != NULL)
	{
		aux = aux->next;
		nodes++;
	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);

		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	subt = aux->next->n - aux->n;
	aux->next->n = subt;
	*head = aux->next;
	free(aux);
}

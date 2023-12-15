#include "monty.h"
/**
 * pop_func -to delete from the stack
 *
 * @head: double pointer to the first node on the
 * stack
 * @counter: line number
 */
void pop_func(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: Can't pop an empty stack\n", counter);

		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;

	if (*head != NULL)
		(*head)->prev = NULL;
	free(h);
}

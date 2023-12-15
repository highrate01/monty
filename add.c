#include "monty.h"

/**
 * add_func - add the  elemnt of the stack
 * @head: double pointer to the first node
 * @counter: line number
 * Description: it aadd the top two element of the stack
 * Return: no return
 */
void add_func(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;

	while (h != NULL)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: cant't add, stack too short\n", counter);
		return;

	 fclose(bus.file);
	 free(bus.content);
	 free_stack(*head);
	 exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

#include "monty.h"

/**
 * pstr_func - prints string at the top of stack
 *
 * @head: double pointer to the stack
 * @counter: line number
 * Return: nothin
 */
void pstr_func(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void) counter;

	h = *head;
	while (h != NULL)
	{
		if (h->n > 127 || h->n <= 0)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

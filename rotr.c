#include "monty.h"

/**
 * rotr_func - rotates the stack to the bottom
 * @head: double pointer to the stack
 * @counter: line number
 * Return: nothing
 */
void rotr_func(stack_t **head, __attribute__((unused))unsigned int counter)
{
	stack_t *copy;

	copy = *head;

	if (*head == NULL || (*head)->next == NULL)
		return;
	while (copy->next)
		copy = copy->next;
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = copy;
	(*head)->prev = copy;
	(*head) = copy;
}

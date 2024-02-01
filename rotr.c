#include "monty.h"

/**
 * rotr_func - rotates the stack to the bottom
 * @stack: double pointer to the stack
 * @line_number: line number
 * Return: nothing
 */
void rotr_func(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *copy;

	copy = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (copy->next)
		copy = copy->next;
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = copy;
	(*stack)->prev = copy;
	(*stack) = copy;
}

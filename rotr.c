#include "monty.h"
/**
 * f_rotl - rotates the stack to the top.
 *
 * @stack: pointer to the first node of the stack
 * @line_number: line number of the list
 * Return: nothing
 */
void f_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *upper, *lower;
	(void)line_number;

	if ((*stack)->next == NULL || (*stack)->next == NULL)
		return;
	upper = (*stack)->next;
	lower = (*stack)->next;
	while (lower->next != NULL)
		lower = lower->next;
	upper->next->prev = *stack;
	(*stack)->next = upper->next;
	lower->next = upper;
	upper->next = NULL;
	upper->prev = lower;
}
/**
 * f_rotr - rotates the stack to the bottom
 *
 * @@stack: pointer to the first node of the stack
 * @line_number: line number of the list
 * Return: nothing
 */
void f_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *upper, *lower;
	(void)line_number;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	upper = (*stack)->next;
	lower = (*stack)->next;

	while (lower->next != NULL)
		lower = lower->next;
	lower->prev->next = NULL;
	(*stack)->next = lower;
	lower->prev = *stack;
	lower->next = upper;
	upper->prev = lower;
}
/**
 * f_stack - sets the format of the data to a stack (LIFO)
 *
 * @stack: pointer to the first node of the stack
 * @line_number: line number of the list
 * Return: nothing
 */
void f_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
/**
 * f_queue - convert stack to queue
 *
 * @stack: pointer to the first node of the stack
 * @line_number: line number of the list
 * Return: nothing
 */
void f_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

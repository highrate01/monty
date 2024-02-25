#include "monty.h"

/**
 * f_pall - prints all the values on the stack, starting from the top
 * of the stack
 * @stack: pointer to the first node
 * @line_number: line number of the file
 * Return: nothing
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
/**
 * f_pint - prints the value at the top of the stack, followed
 * by a new line
 *
 * @stack: pointer to the first node
 * @line_number: line number of the file
 * Return: nothing
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_error(error_pint(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}
/**
 * f_pop - removes the top element of the stack
 * @stack: pointer to the first node
 * @line_number: line number of the file
 * Return: nothing
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if ((*stack)->next == NULL)
	{
		set_op_error(error_pop(line_number));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
/**
 * f_swap - swaps the top two elements of the stack
 * @stack: pointer to the first node
 * @line_number: line number of the file
 * Return: nothing
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_error(short_stack(line_number, "swap"));
		return;
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;

	if (tmp->next)
		tmp->next = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}

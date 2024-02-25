#include "monty.h"
/**
 * f_nop - doesn’t do anything
 * @stack: pointer to the first node
 * @line_number: line number of the list
 * Return: nothing
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * f_pchar - prints the char at the top of the stack, followed by a
 * new line
 * @stack: pointer to the first node
 * @line_number: line number of the list
 * Return: nothing
 */
void f_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_error(error_pchar(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_error(error_pchar(line_number, "valuee out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}
/**
 * f_pstr - prints the string starting at the top of the stack
 * followed by a new line.
 *
 * @stack: pointer to the first node
 * @line_number: line number of the list
 * Return: nothing
 */
void f_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n !=  0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_number;
}

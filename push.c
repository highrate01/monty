#include "monty.h"

/**
 * f_push - pushes an element to the stack
 *
 * @stack: double pointer to the beginning of the node
 * @line_number: current line number of the list
 * */
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = (stack_t *) malloc(sizeof(stack_t));

	if (new == NULL)
	{
		set_op_error(malloc_error());
		return;
	}
	if (op_tok[1] == NULL)
	{
		set_op_error(int_error(line_number));
			return;
	}
	for (i = 0; op_tok[1][i]; i++)
	{
		if (op_tok[1][i] == '-' && i == 0)
			continue;
		if (op_tok[1][i] < '0' || op_tok[1][i] > '9')
		{
			set_op_error(int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_tok[1]);

	if (check_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;

		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

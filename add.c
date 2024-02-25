#include "monty.h"

/**
 * f_add - adds to two values of linked list
 *
 * @stack: pointer to the top of the list
 * @line_number: line number
 * Return: void
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_error(short_stack(line_number, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	f_pop(stack, line_number);
}
/**
 * f_sub - subtract the two values from top in linked list
 *
 * @stack: pointer to the top of the list
 * @line_number: line number
 * Return: void
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_error(short_stack(line_number, "sub"));
		return;
	}
	(*stack)->next->next->n -= (*stack)->next->n;
	f_pop(stack, line_number);
}
/**
 * f_div - divide the second value from the top value
 *
 * @stack: pointer to the top of the list
 * @line_number: line number
 * Return: nothing
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_error(short_stack(line_number, "div"));
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	f_pop(stack, line_number);
}
/**
 * f_mul - multiplies the second and first value
 *
 * @stack: pointer to the top of the list
 * @line_number: line number
 * Return: void
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_error(short_stack(line_number, "mul"));
		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	f_pop(stack, line_number);
}
/**
 * f_mod - computes the modulus of the two values in first and second lists
 *
 * @stack: pointer to the top of the list
 * @line_number: line number
 * Return: nothing
 * Description: the result gotten from the modulus operation will be stored
 * in the second node
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_error(short_stack(line_number, "mod"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		set_op_error(error_div(line_number));
		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	f_pop(stack, line_number);
}


#include "monty.h"

/**
 * error_pop - Prints error message for empty stacks
 * @line_number: line number where error occur
 * Return: Exit failure
 */

int error_pop(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * error_pint - prints error message for pint(empty stack)
 * @line_number: line number where error occur
 * Return: Eit failure
 */

int error_pint(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * stack_short - stack too short error message for stacks smaller than two
 * @line_number: line number at which error error occurs
 * @op: operations
 * Return: exit failure
 */
int short_stack(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't open %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}
/**
 * error_div - error messages for division by 0
 * @line_number: line number where the message occurs
 * Return: exit failure
 */
int error_div(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * error_pchar - pchar error messages for empty stack
 * @line_number: line where error occurs
 * @op: error message to print
 */
int error_pchar(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, op);
	return (EXIT_FAILURE);
}

#include "monty.h"

/**
 * malloc_error - prints error when malloc fails
 * Return: EXIT_FAILURE
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * int_error - prints invalid message
 * @line_number: line number where error occur
 * Return: EXIT FAILURE
 */
int int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * usage_error - prints usage error message
 *
 * Return: Exit Failure
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * open_error - Print error message when file fails to open
 * @filename: name of file to open
 * Return: Exit failure
 */

int open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file%s\n", filename);
	return (EXIT_FAILURE);
}
/**
 * op_error - prints unknown instruction message
 * @op_code: Opcode error
 * @line_number: line number
 * Return: Exit Failure
 */
int op_error(char *op_code, int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op_code);
	return (EXIT_FAILURE);
}

#include "monty.h"
/**
 * check_digit - check for digit
 * @str: pointer to string
 * Return: 0 if true, otherwise 1
 */
static int check_digit(char *str)
{
	int j;

	for (j = 0; str[j]; j++)
	{
		if (str[j] == '-' && j == 0)
			continue;
		if (isdigit(str[j]) == 0)
			return (1);
	}
	return (0);
}

/**
 * push_element - add element to the stack
 * @stack: pointer to the first element
 * @line_number: count
 * Return: no return
 */
void push_element(stack_t **stack, unsigned int line_number)
{
	char *line;
	int n;

	line = strtok(NULL, "\n\t\r ");
	if (line == NULL || check_digit(line))
	{
		dprintf(STDOUT_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(line);
	if (!add_node(stack, n))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.len++;
}

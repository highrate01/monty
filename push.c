#include "monty.h"

/**
 * push_element - add element to the stack
 * @stack: pointer to the first element
 * @line_number: count
 * Return: no return
 */
void push_element(stack_t **stack, unsigned int line_number)
{
	const char *line = NULL;
	int num;
	char *token;
	stack_t *new_node;

	char *line_copy = strdup(line);

	token = strtok(line_copy, " ");
	if (token == NULL)
	{
		fprintf(stderr, "Error: Invalid input\n");
		exit(EXIT_FAILURE);
	}
	if (_strcmp(token, "push") != 0)
	{
		fprintf(stderr, "Error: Expected 'push' keyword\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " ");
	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	num = _atoi(token);
	if (num == 0 && *token != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = (stack_t *) malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->next = *stack;
	*stack = new_node;
	free(line_copy);
}

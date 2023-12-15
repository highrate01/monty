#include "monty.h"
/**
 * exec - to execute the op_code
 * @stack: double pointer to linked list stack
 * @counter: line counter
 * @file: pointer to file
 * @content: line number
 * Return: int
 */
int exec(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	_opcode_t opst[] = {
		{"push", push_element},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mull_func},
		{"mod", modification},
		{"pchar", pchar_func},
		{"pstr", pstr_func},
		{"rotl", rotl_func},
		{"rotr", rotr_func},
		{"stack", stack_func},
		{"queue", queue_func},
		{NULL, NULL}
	};
	
	char *op;
	unsigned int i = 0;

	op = strtok(content, "\n\t ");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, "\n\t ");
	while (opst[i].opcode != NULL && op != NULL)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].func(stack, counter);
			return (0);
		}
		i++;
	}
	if (op != NULL && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

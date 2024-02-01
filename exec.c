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
	size_t i;
	instruction_t opst[] = {
		{"push", push_element},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{"pchar", pchar_func},
		{"pstr", pstr_func},
		{"rotl", rotl_func},
		{"rotr", rotr_func},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	for (i = 0; opst[i].opcode != NULL; i++)
	{
		if (strcmp(opst[i].opcode, content) == 0)
		{
			opst[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instructions %s\n", line_number, content);
	exit(EXIT_FAILURE);
}

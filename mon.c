#include "monty.h"

/**
 * free_tok - free global tok
 *
 * Return: void
 */
void free_tok(void)
{
	size_t i = 0;

	if (op_tok == NULL)
		return;
	for (i = 0; op_tok[i]; i++)
		free(op_tok[i]);
	free(op_tok);
}
/**
 * token_len - get the length of current token
 *
 * Return: length of current tok
 */
unsigned int token_len(void)
{
	unsigned int tok_len = 0;

	while (op_tok[tok_len])
		tok_len++;
	return (tok_len);
}
/**
 * empty_line - checks if line from getline only contains delimiter
 *
 * @line: pointer to line
 * @delim: delimiter
 * Return: 1 if true, 0 otherwise
 */
int empty_line(char *line, char *delim)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[i] == delim[j])
				break;
		}
		if (delim[j] == '\0')
			return (0);
	}
	return (1);
}
/**
 * op_func - matche each op_code with the corresponding function
 * @op_code: The op_code to match the function with
 * Return: pointer to corresponding function
 */
void (*get_func(char *opcode))(stack_t**, unsigned int)
{
	int i;

	instruction_t op_funcs[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"pop", f_pop},
		{"add", f_add},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"nop", f_nop},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"stack", f_stack},
		{"queue", f_queue},
		{NULL, NULL}
	};
	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}
/**
 * file_func - function to execute script
 *
 * @fd: file descriptor
 * Return: EXIT_SUCCESS on success
 */
int file_func(FILE *fd)
{
	stack_t *stack = NULL;

	char *line = NULL;
	size_t len = 0;
	size_t exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void(*op_func)(stack_t **, unsigned int);

	if (inti_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (fgets(line, len, fd) != NULL)
	{
		line_number++;
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		op_tok = strtow(line, DELIMS);
		if (op_tok == NULL)
		{
			if (empty_line(line, DELIMS))
				continue;
			return (malloc_error());
		}
		else if (op_tok[0][0] == '#')
		{
			free_tok();
			continue;
		}
		op_func = get_func(op_tok[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = op_error(op_tok[0], line_number);
			free_tok();
			break;
		}
		prev_tok_len = token_len();
		op_func(&stack, line_number);
		if (token_len() != prev_tok_len)
		{
			if (op_tok && op_tok[prev_tok_len])
				exit_status = atoi(op_tok[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tok();
			break;
		}
		free_tok();
	}
	free_stack(&stack);
	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}
	free(line);
	return (exit_status);
}

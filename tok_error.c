#include "monty.h"

/**
 * set_op_error - set op_toks last element to error code
 *
 * @err: integer to store in a string
 * Return: nothing
 */
void set_op_error(int err)
{
	int tok_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_tok = NULL;

	tok_len = token_len();
	new_tok = malloc(sizeof(char *) * (tok_len + 2));
	if (!op_tok)
	{
		malloc_error();
		return;
	}
	while (i < tok_len)
	{
		new_tok[i] = op_tok[i];
		i++;
	}
	exit_str = get_int(err);
	if (!exit_str)
	{
		free(new_tok);
		malloc_error();
		return;
	}
	new_tok[i++] = exit_str;
	new_tok[i] = NULL;
	free(op_tok);
	op_tok = new_tok;
}

#include "monty.h"
char **op_tok = NULL;
/**
 * main - entry point
 * @argc: argument count
 * @argc: argument vector
 * Return: exit success on success exit failure otherwise
 */
int main(int argc, char **argv)
{
	FILE *fd = NULL;
	int exit_status = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return(open_error(argv[1]));
	exit_status = file_func(fd);
	fclose(fd);
	return (exit_status);
}

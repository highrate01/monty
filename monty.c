#include "monty.h"

/**
 * main - input
 * @argc: arguement count
 * @argv: arguement vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	unsigned int counter = 0;
	char *line = NULL, *opst = NULL;
	size_t n = 0;
	FILE *file = NULL;
	stack_t *stack = NULL;

	var.queue = 0;
	var.len = 0;
	if (argc != 2)
	{
		fprintf(stderr, "usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		counter++;
		opst = strtok(&line, "\n\t\r ");
		if (opst != NULL && opst[0] != '#')
			exec(opst, &stack, counter);
	}
	if (ferror(file))
	{
		perror("Error reading file");
		exit(EXIT_FAILURE);
	}
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}


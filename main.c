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
	char *line = NULL;
	size_t len = 0;
	FILE *file;

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
		counter++;
	if (ferror(file))
	{
		perror("Error reading file");
		exit(EXIT_FAILURE);
	}
	free(line);
	fclose(file);
	return(EXIT_SUCCESS);
}


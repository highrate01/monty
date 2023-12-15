#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - input
 * @argc: arguement count
 * @argv: arguement vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char content[MAX_LINE_SIZE];
	FILE *file;

	/*size_t size = 0;*/
	/*ssize_t read_line = 1;*/
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Cant't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(content, sizeof(content), file) != NULL)
	{
		content[strcspn(content, "\n")] = '\0';
		bus.content = content;
		counter++;
		exec(content, &stack, counter, file);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}


#include "monty.h"

/**
 * _fclose - close file
 * @current: exit
 * @head: pointer
 * Return: nothing
 */
void _fclose(int current, void *head)
{
	FILE *file;
	(void)current;

	file = (FILE *) head;
	fclose(file);
}

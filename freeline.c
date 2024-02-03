#include "monty.h"

/**
 * freeline - free line
 * @current: exit
 * @head: pointer to line
 * Return: nothing
 */
void freeline(int current, void *head)
{
	char **line = head;

	(void)current;
	if (*line != NULL)
		free(*line);
}

#include "monty.h"

/**
 * get_int - get a character pointer to new string
 * containing pointer
 *
 * @number: integer to convert
 * Return: NULL if malloc fails, otherwise  character pointer
 */
char *get_int(int number)
{
	unsigned int tmp;
	char *get;

	int length = 0;
	long num = 0;
	tmp = _abs(number);
	length = get_len(tmp, 10);

	if (number < 0 || num < 0)
	{
		length++;
	}
	get = malloc(length + 1);
	if (!get)
		return (NULL);
	fill_number_buff(tmp, 10, get, length);
	if (number < 0 || num < 0)
		get[0] = '-';
	return (get);
}
/**
 * _abs - absolute value
 * @i: integer to get
 * Return: unsigned int
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}
/**
 * get_len -  gets length of buffer
 *
 * @num: number to get the length neeeded for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length
 */
int get_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_number_buff - fills buffeer
 *
 * @num: number to convert
 * @base: base of number used
 * @buff: buffer to fill with result
 * @buff_size: size of beffer in bytes
 *
 * Return: always void
 */
void fill_number_buff(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int get, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		get = num % base;
		if (get > 9)
			buff[i] = get + 87;
		else
			buff[i] = get + '0';
		num /= base;
		i--;
	}
}

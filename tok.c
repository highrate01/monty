#include "monty.h"
/**
 * strtow = tokenize string
 *
 * @_str: takes string to tokenize
 * @delim: delimitor to use
 * Return: 2d arrays of pointer
 */
char **strtow(char *_str, char *delim)
{
	char **word = NULL;
	int word_count, word_len, n, i = 0;

	if (_str == NULL || !*_str)
		return (NULL);
	word_count = get_count(_str, delim);

	if (word_count == 0)
		return (NULL);
	word = malloc((word_count + 1) * sizeof(char *));
	if (word == NULL)
		return (NULL);
	while (i < word_count)
	{
		word_len = get_count_length(_str, delim);
		if (_isdelim(*_str, delim))
		{
			_str = get_next_word(_str, delim);
		}
		word[i] = malloc((word_len + 1) * sizeof(char));
		if (word[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(word[i]);
			}
			free(word);
			return (NULL);
		}
		n = 0;
		while (n < word_len)
		{
			word[i][n] = *(_str + n);
			n++;
		}
		word[i][n] = '\0';
		_str = get_next_word(_str, delim);
		i++;
	}
	word[i] = NULL;
	return (word);
}
/**
 * _isdelim - check for delimiter error
 *
 * @cha: character in stream
 * @delim: pointer to null terminated array
 *
 * Return: 1 on success, 0 therwiae
 */
int _isdelim(char cha, char *delim)
{
	int i = 0;

	while (delim[i])
	{
		if (delim[i] == cha)
			return (i);
		i++;
	}
	return (0);
}
/**
 * get_count_length - get the word length in str
 * @str: string to get word from
 * delim: delimitor
 * Return: length of word
 */
int get_count_length(char *str, char *delim)
{
	int word_len, pend = 1, i = 0;

	while (*(str + i))
	{
		if (_isdelim(str[i], delim))
			pend = 1;
		else if (pend)
			word_len++;
		if (word_len > 0 && _isdelim(str[i], delim))
			break;
		i++;
	}
	return (word_len);
}
/**
 * get_count - gets word count of string
 *
 * @str: string to get the word count
 * @delim: delimitor
 * Return: word_count
 */
int get_count(char *str, char *delim)
{
	int word_count = 0, pend = 1, i = 0;

	while (*(str + i))
	{
		if (_isdelim(str[i], delim))
			pend = 1;
		else if (pend)
		{
			pend = 0;
			word_count++;
		}
		i++;
	}
	return (word_count);
}
/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get the next word from
 * @delim: delimitor
 * Return: pointer to first character
 */
char *get_next_word(char *str, char *delim)
{
	int pend = 1;
	int i = 0;

	while (*(str + i))
	{
		if (_isdelim(str[i], delim))
			pend = 1;
		else if (pend)
			break;
		i++;
	}
	return (str + i);
}

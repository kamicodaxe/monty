#include "monty.h"
#include <ctype.h>

/**
 * _strtok_r - Custom reentrant strtok function.
 * @str: String to tokenize.
 * @delim: Delimiter characters.
 * @saveptr: Save pointer for reentrancy.
 *
 * Description:
 * Custom reentrant strtok function that tokenizes a string using the given
 * delimiters and maintains reentrancy through a save pointer.
 *
 * Return:
 * Next token in the string, or NULL if no more tokens are found.
 */
char *_strtok_r(char *str, const char *delim, char **saveptr)
{
	char *token;

	if (str == NULL && *saveptr == NULL)
		return (NULL);

	if (str != NULL)
		*saveptr = str;

	while (**saveptr && strchr(delim, **saveptr))
		(*saveptr)++;

	if (**saveptr == '\0')
		return (NULL);

	token = *saveptr;

	*saveptr = strpbrk(*saveptr, delim);

	if (*saveptr != NULL)
	{
		*(*saveptr) = '\0';
		(*saveptr)++;
	}

	return (token);
}

/**
 * is_numeric - Checks if a string is a numeric value.
 * @str: String to check.
 *
 * Return: 1 if numeric, 0 otherwise.
 */
int is_numeric(const char *str)
{
	if (!str)
		return (0);

	if (*str == '-')
		str++;

	if (!isdigit(*str))
		return (0);

	return (1);
}

#include "monty.h"
#include <string.h>

/**
 * error_usage - print usage err in stderr
 *
 * Return: Status(1) always
 */
int error_usage(void)
{
	fprintf(stderr, "USAGE: monty file");

	return (EXIT_FAILURE);
}

/**
 * error_open_file - Prints open file err in stderr
 * @path: Path to file
 *
 * Return: Status(1) always
 */
int error_open_file(char *path)
{
	fprintf(stderr, "Error: Can't open file %s\n", path);

	return (EXIT_FAILURE);
}

/**
 *  error_unknown_cmd - Handles unkwown optcode
 */
void error_unknown_cmd(void)
{
}

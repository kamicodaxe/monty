#include "monty.h"
#include <string.h>

void error_usage()
{
}

void error_open_file(char *path)
{
	char *error_message = "Error: Can't open file";

	error_message = strcat(error_message, path);

	write(2, error_message, strlen(error_message));

	exit(EXIT_FAILURE);
}

void error_unknown_cmd()
{
}

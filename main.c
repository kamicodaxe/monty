#include "monty.h"
stack_t *stack = NULL;

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Description: Validates command-line arguments, opens and reads the Monty
 * bytecode file, and interprets the instructions.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char **argv)
{
	char *data = NULL;
	int fd;

	if (argc != 2)
		return (error_usage());

	/* Open monty file path */
	fd = open_file(argv[1]);
	if (fd == -1)
		return (error_open_file(argv[1]));

	if ((read_bytes(fd, &data) == -1))
		return (error_open_file(argv[1]));

	/* Parse monty file */
	parse_monty_file(data);

	/* Free allocated memory and exit */
	free_stack(stack);
	free(data);

	return (EXIT_SUCCESS);
}

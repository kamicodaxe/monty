#include "monty.h"

/**
 * find_instruction - Find the function pointer for the given opcode.
 * @opcode: Opcode to search for.
 * Return: Function pointer if found, NULL otherwise.
 */
void (*find_instruction(char *opcode))(char *, char *, unsigned int)
{
	size_t i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		/* Add other instructions as needed */
		{NULL, NULL} /* Terminate the array with NULL values */
	};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (instructions[i].f);
	}

	fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
	exit(EXIT_FAILURE);
}

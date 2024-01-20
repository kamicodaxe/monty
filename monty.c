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
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
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

/**
 * parse_monty_file - Parses a Monty bytecode file and executes instructions.
 * @data: Contents of the Monty file.
 *
 * Description: Parses each line of the Monty file, extracts the opcode and
 * argument, and executes the corresponding instruction.
 */
void parse_monty_file(char *data)
{
	char *opcode, *token, *arg;
	unsigned int line_number = 1;
	char *saveptr_op, *saveptr_arg;
	void (*instruction_func)(char *, char *, unsigned int);

	token = _strtok_r(data, "\n", &saveptr_op);

	while (token)
	{
		opcode = _strtok_r(token, " \t", &saveptr_arg);

		if (opcode && opcode[0] != '#') /* Ignore comments */
		{
			/*Get the argument, if any*/
			arg = _strtok_r(NULL, " \t", &saveptr_arg);

			/*Find the corresponding function for the opcode*/
			instruction_func = find_instruction(opcode);

			/*Call the instruction function*/
			if (instruction_func != NULL)
			{
				instruction_func(opcode, arg, line_number);
			}
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}

		token = _strtok_r(NULL, "\n", &saveptr_op);
		line_number++;
	}
}

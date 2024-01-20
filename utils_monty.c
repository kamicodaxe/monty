#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Creates a new node with the given value and adds it to
 * the top of the stack.
 */
void push(char *opcode, char *value_str, unsigned int line_number)
{
	int value;
	(void)opcode;

	if (!value_str || !is_numeric(value_str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);

	if (add_node(&stack, value) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - Prints all elements of the stack.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Prints all the elements of the stack, starting from
 * the top.
 */
void pall(char *opcode, char *value_str, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	(void)value_str;
	(void)opcode;

	if (!stack)
	{
		/* Print nothing */
		exit(EXIT_SUCCESS);
	}

	current = stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints head element of the stack.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Prints head element of the stack
 */
void pint(char *opcode, char *value_str, unsigned int line_number)
{
	(void)line_number;
	(void)value_str;
	(void)opcode;

	if (stack != NULL)
		printf("%d\n", stack->n);
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

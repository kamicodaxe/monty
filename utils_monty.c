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

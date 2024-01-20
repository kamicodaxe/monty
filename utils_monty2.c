#include "monty.h"

/**
 * pop - Deletes head element of the stack.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Deletes head element of the stack
 */
void pop(char *opcode, char *value_str, unsigned int line_number)
{
	(void)value_str;
	(void)opcode;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	if (!stack->next)
	{
		free(stack);
		stack = NULL;
		return;
	}

	stack = stack->next;
	free(stack->prev);
	stack->prev = NULL;
}

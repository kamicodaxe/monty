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

/**
 * swap - Swaps the top two elements of the stack.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Swaps the top two elements of the stack.
 */
void swap(char *opcode, char *value_str, unsigned int line_number)
{
	stack_t *tmp = stack->next;

	(void)value_str;
	(void)opcode;

	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = stack->next;

	stack->next = tmp->next;
	stack->prev = tmp;

	tmp->next = stack;
	tmp->prev = NULL;

	stack = tmp;
}

/**
 * add - Adds the top two elements of the stack.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Adds the top two elements of the stack.
 */
void add(char *opcode, char *value_str, unsigned int line_number)
{
	stack_t *tmp;

	(void)value_str;
	(void)opcode;

	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = stack->next;

	tmp->n = stack->n + tmp->n;
	free(tmp->prev);
	tmp->prev = NULL;

	stack = tmp;
}

/**
 * nop - Doesn’t do anything.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Doesn’t do anything.
 */
void nop(char *opcode, char *value_str, unsigned int line_number)
{
	(void)opcode;
	(void)value_str;
	(void)line_number;
}

/**
 * sub - Subtracts the top two elements of the stack.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Subtracts the top two elements of the stack.
 */
void sub(char *opcode, char *value_str, unsigned int line_number)
{
	stack_t *tmp;

	(void)value_str;
	(void)opcode;

	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = stack->next;

	tmp->n = tmp->n - stack->n;
	free(tmp->prev);
	tmp->prev = NULL;

	stack = tmp;
}

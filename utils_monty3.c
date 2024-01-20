#include "monty.h"

/**
 * _div - Divides the top two elements of the stack.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Divides the top two elements of the stack.
 */
void _div(char *opcode, char *value_str, unsigned int line_number)
{
	stack_t *tmp;

	(void)value_str;
	(void)opcode;

	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (stack->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = stack->next;

	tmp->n = tmp->n / stack->n;
	free(tmp->prev);
	tmp->prev = NULL;

	stack = tmp;
}

/**
 * mul - Multiplication of the top two elements of the stack.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Multiplication of the top two elements of the stack.
 */
void mul(char *opcode, char *value_str, unsigned int line_number)
{
	stack_t *tmp;

	(void)value_str;
	(void)opcode;

	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = stack->next;

	tmp->n = tmp->n * stack->n;
	free(tmp->prev);
	tmp->prev = NULL;

	stack = tmp;
}

/**
 * mod - Modular division of the top two elements of the stack.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Modular division of the top two elements of the stack.
 */
void mod(char *opcode, char *value_str, unsigned int line_number)
{
	stack_t *tmp;

	(void)value_str;
	(void)opcode;

	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (stack->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = stack->next;

	tmp->n = tmp->n % stack->n;
	free(tmp->prev);
	tmp->prev = NULL;

	stack = tmp;
}

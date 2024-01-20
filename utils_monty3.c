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

/**
 * pchar - Prints the char at the top of the stack, followed by a new line
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Prints the char at the top of the stack, followed by a new line
 */
void pchar(char *opcode, char *value_str, unsigned int line_number)
{
	(void)value_str;
	(void)opcode;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	if (stack->n < 33 || stack->n > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	printf("%c\n", stack->n);
}

/**
 * pstr - Prints the string starting at the top of the stack,
 * followed by a new line.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number in the Monty file where the opcode appears.
 *
 * Description: Prints the string starting at the top of the stack,
 * followed by a new line.
 */
void pstr(char *opcode, char *value_str, unsigned int line_number)
{
	stack_t *head_copy;

	(void)value_str;
	(void)opcode;
	(void)line_number;

	if (stack == NULL)
	{
		printf("\n");
		return;
	}

	head_copy = stack;
	while (head_copy != NULL)
	{
		if (head_copy->n < 33 || head_copy->n > 126)
			break;

		printf("%c", head_copy->n);
		head_copy = head_copy->next;
	}

	printf("\n");
}

/**
 * rotl - rotates the stack to the top.
 * @opcode: opcode string.
 * @value_str: String value
 * @line_number: Line number
 * in the Monty file where the opcode appears.
 *
 * Description: rotates the stack to the top.
 */
void rotl(char *opcode, char *value_str, unsigned int line_number)
{
	stack_t *head_copy;
	stack_t *tail_copy;

	(void)value_str;
	(void)opcode;
	(void)line_number;

	if (stack == NULL || (stack != NULL && stack->next == NULL))
		return;

	head_copy = stack;
	tail_copy = stack;
	while (tail_copy->next != NULL)
		tail_copy = tail_copy->next;

	/* Last but one element becomes last */
	head_copy->next->prev = NULL;
	stack = head_copy->next;
	head_copy->next = NULL;
	head_copy->prev = tail_copy;

	tail_copy->next = head_copy;
}

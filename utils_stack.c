#include "monty.h"
#include <ctype.h>

/**
 * add_node - Adds a new node at the beginning of a stack.
 * @stack: Double pointer to the head of the stack.
 * @n: Value to be added to the new node.
 *
 * Return: Address of the new node, or NULL on failure.
 */
stack_t *add_node(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}

/**
 * free_stack - Frees all nodes in the stack.
 * @stack: Pointer to the head of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

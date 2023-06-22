#include "monty.h"

/**
 * pop - function that removes the top values from stack
 * @stack: target stack
 * @line_number: current line command is on
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

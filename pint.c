#include "monty.h"

/**
 * pint - function that prints the value at the top of the stack
 * @stack: target stack
 * @line_number: current line command is on
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "l%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

#include "monty.h"

/**
 ** pchar - function prints the char at the top of the stack
 ** @stack: Target stack
 ** @line_number: current line command is on
 ** Return: Nothing
 **/
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}

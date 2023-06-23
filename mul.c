#include "monty.h"

/**
 ** mul - A function that multiplies the top two elements of a stack
 ** @stack: target stack
 ** @line_number: current line command is in
 ** Return: Nothing
 **/
void mul(stack_t **stack, unsigned int line_number)
{
	int multiple;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	multiple = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = multiple;
	pop(stack, line_number);
}

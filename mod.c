#include "monty.h"

/**
 ** mod - A function that computes the rest of the division of the top two elements of a stack
 ** @stack: target stack
 ** @line_number: current line command is in
 ** Return: Nothing
 **/
void mod(stack_t **stack, unsigned int line_number)
{
	int modulus;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	modulus = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = modulus;
	pop(stack, line_number);
}

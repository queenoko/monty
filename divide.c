#include "monty.h"

/**
 ** divide - A function that divides the top two elements of a stack
 ** @stack: target stack
 ** @line_number: current line command is in
 ** Return: Nothing
 **/
void divide(stack_t **stack, unsigned int line_number)
{
	int divide;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	divide = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = divide;
	pop(stack, line_number);
}

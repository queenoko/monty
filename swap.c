#include "monty.h"

/**
 ** swap - A function that swaps the top two elements of a stack
 ** @stack: target stack
 ** @line_number: current line command is on
 ** Return: Nothing
 **/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

#include "monty.h"

/**
 ** sub - A function that substracts the top two elements of a stack
 ** @stack: target stack
 ** @line_num: current line command is in
 ** Return: Nothing
 **/
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

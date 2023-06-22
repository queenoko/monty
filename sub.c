#include "monty.h"

/**
 ** sub - A function that substracts the top two elements of a stack
 ** @stack: target stack
 ** @line_num: current line command is in
 ** Return: Nothing
 **/
void sub(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = temp;
	pop(stack, line_number);
}

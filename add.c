#include "monty.h"

/**
 ** add - A function that adds the top two elements of a stack
 ** @stack: target stack
 ** @line_number: current line command is in
 ** Return: Nothing
 **/
void add(stack_t **stack, unsigned int line_number)
{
	int addition;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	addition = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = addition;
	pop(stack, line_number);
}

#include "monty.h"

/**
 ** rotr - function rotates the stack to the bottom
 ** @stack: target stack
 ** @line_number: current line command is on
 ** Return: nothing
 **/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *rotate = *stack;
	(void)line_number;

	if (rotate && rotate->next)
	{
		while (rotate->next)
			rotate = rotate->next;
		rotate->prev->next = NULL;
		rotate->next = *stack;
		(*stack)->prev = rotate;
		*stack = rotate;
		rotate->prev = NULL;
	}
}

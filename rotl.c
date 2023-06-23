#include "monty.h"

/**
 ** rotl - function rotates the stack to the top
 ** @stack: target stack
 ** @line_number: current line command is on
 ** Return: Nothing
 **/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (temp && temp->next)
	{
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		temp->next->next = NULL;
	}
}


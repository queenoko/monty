#include "monty.h"

/**
 * pall - function that prints out values in a stack
 * @stack: pointer to stack where values are stored
 * @line_number: current line command is
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

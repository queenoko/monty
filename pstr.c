#include "monty.h"

/**
 ** pstr - function prints a string starting at the top of the stack
 ** @stack: target stack
 ** @line_number: current line command is on
 ** Return: Nothing.
 **/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp->n >= 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

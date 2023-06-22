#include "monty.h"

/**
 ** push - A function that pushes value to stack.
 ** @stack: Target stack.
 ** @line_number: line of current command
 ** Return: EXIT_SUCCESS on success
 **/
void push(stack_t **stack, unsigned int line_number)
{
	char *value;
	int i = 0;
	(void)line_number;

	value = strtok(NULL, " \n");
	if (value == NULL)
	{
		fprintf(stderr, "usage: push integer\n");
		exit(EXIT_FAILURE);
	}
	i = atoi(value);
	stack_push(stack, i);
}


/**
 * stack_push - function that pushes values to stack
 * @stack: pointer to target stack
 * @value: value to push
 * Return: Nothing
 */
void stack_push(stack_t **stack, int value)
{
	stack_t *new_stack;

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_stack->n = value;
	new_stack->next = *stack;
	new_stack->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new_stack;
	*stack = new_stack;
}

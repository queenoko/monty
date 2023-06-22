#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 ** exec - function that puts commands in tokens
 ** @mfile: open file to read commands from
 ** Return: 1 if successful
 **/
void exec(FILE *mfile)
{
	stack_t *stack = NULL;
	char *readline = NULL;
	char *token;
	size_t i = 0;
	unsigned int line_number = 0;

	while (getline(&readline, &i, mfile) != -1)
	{
		line_number++;
		token = strtok(readline, " \t\r\n\a\"");
		if (token == NULL)
			continue;
		run(&stack, token, line_number);
	}
	freeStack(&stack);
	free(readline);
}


/**
 ** run - function that runs through an array for the right func
 ** @stack: pointer to stack to edit
 ** @token: pointer to char to check for function name
 ** @line_number: line number of command
 ** Return: Exit success on success and exit failure on failure
 **/
int run(stack_t **stack, char *token, unsigned int line_number)
{
	unsigned int a = 0;

	instruction_t func[] = {
		{"push", &push},
		{"pall", &pall},
		{"null", NULL}
	};
	while (a < 3)
	{
		if (strcmp(token, func[a].opcode) == 0)
		{
			func[a].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
		a++;
	}
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, token);
	freeStack(stack);
	return (EXIT_FAILURE);
}


/**
 ** freeStack - function that frees memory for stack.
 ** @stack: a ponter to stack to free.
 ** Return: nothing
 **/

void freeStack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

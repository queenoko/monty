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
		if (token == NULL || token[0] == '#')
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
void run(stack_t **stack, char *token, unsigned int line_number)
{
	unsigned int a = 0;

	instruction_t func[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"sub", &sub},
		{"div", &divide},
		{"mul", &mul},
		{"mod", &mod},
		{"pchar", &pchar},
		{"pstr", &pstr},
		{"rotl", &rotl},
		{"rotr", &rotr},
		{"nop", &nop}
	};
	while (a < 15)
	{
		if (strcmp(token, func[a].opcode) == 0)
		{
			func[a].f(stack, line_number);
			return;
		}
		a++;
	}
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, token);
	freeStack(stack);
	exit(EXIT_FAILURE);
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

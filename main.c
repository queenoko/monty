#include "monty.h"

/**
 * main - main function that reads and run commands
 * from a file
 * @argc: number of arguments
 * @argv: arguments
 * Return: Exit success on success
 */
int main(int argc, char **argv)
{
	FILE *mfile;

	if (argc <= 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	mfile = fopen(argv[1], "r");
	if (mfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	exec(mfile);
	fclose(mfile);
	return (EXIT_SUCCESS);
}

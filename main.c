#include "sh_shell.h"

/**
 * main - load config lines, if any and perform any clean up
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if successful
 */
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *line = malloc(1024 * sizeof(char *));
	char **args;

	while (1)
	{
		printf("#cisfun$ ");
		fget(line, 1024, stdin);
		args = sh_split_line(line);
		sh_launch(args);

		free(line);
		free(args);
	}

	return (0);
}

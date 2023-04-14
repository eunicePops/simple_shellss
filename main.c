#include <stdio.h>

/**
 * main - load config lines, if any and perform any clean up
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = sh_read_line();
		args = sh_split_line(line);
		status = sh_execute(args);

		free(line);
		free(args);
	} while (status);

	return (0);
}

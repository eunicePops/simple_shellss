#include "sh_shell.h"
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

/**
 * sh_split_line - separate arguments from line
 * @line: line(in array of characters) tp be splited
 *
 * Return: tokens
 */
char **sh_split_line(char *line)
{
	int bufsize = TOK_BUFSIZE;
	int position = 0;
	char *token;
	char **tokens;

	tokens = malloc(bufsize * sizeof(char *));
	if (tokens == NULL)
	{
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;

	return (tokens);
}

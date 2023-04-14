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
	int buf_size = TOK_BUFSIZE;
	char *token;
	char **tokens;

	tokens = malloc(bufsize * sizeof(char *));
	if (tokens == NULL)
	{
		exit(EXIT_FAILURE);
	}
	token = sh_strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize *= 2;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				exit(EXIT_FAILURE);
			}
		}
		token = sh_strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;

	return (tokens);
}

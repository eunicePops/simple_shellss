#include "main.h"

void parse_command(char *command, char **args)
{
	char *token;
	int i = 0;

	token = strtok(command, TOK_DELIM);
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, TOK_DELIM);
		i++;
	}
	args[i] = NULL;
}


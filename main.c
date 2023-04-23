#include "main.h"

int main()
{
	int i;
	char *command = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));
	char **arguments = (char **) malloc(MAX_ARGUMENTS * sizeof(char *));

	for (i = 0; i < MAX_ARGUMENTS; i++)
	{
		arguments[i] = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));
	}

	while (1)
	{
		printf("#cisfun$ ");
		fget(command, MAX_COMMAND_LENGTH, stdin);
		parse_command(command, arguments);
		execute(arguments);
	}

	free(command);
	for (i = 0; i < MAX_ARGUMENTS; i++)
	{
		free(arguments[i]);
	}
	free(arguments);

	return (0);
}

#include "main.h"

int launch(char **args)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		printf("Error: failed to fork child process\n");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) < 0)
		{
			printf("./shell: No such file or directory\n");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}

	return (1);
}

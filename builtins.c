#include "main.h"

int env(__attribute__((unused))char **args)
{
	extern char **environ;
	char** env = environ;

	while (*env != NULL) {
		printf("%s\n", *env);
		env++;
	}
	return (1);
}

int sh_cd(char **args)
{
	if (args[1] == NULL){
		printf("sh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error");
		}
	}
	return (1);
}

int sh_help(__attribute__((unused))char **args)
{
/*	int i;*/

	printf("Type program names and arguments and hit enter.\n");
	printf("The following are built in commands:\n");
/*	for (i = 0; i < num_builtins(); i++)
	{
		printf(" %s\n", builtin_str[i]);
	}
*/	return (1);
}

int sh_exit(__attribute__((unused))char **args)
{
	exit(EXIT_SUCCESS);
}

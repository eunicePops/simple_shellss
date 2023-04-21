#include "main.h"

int (*get_function(char *s))(char **args)
{
	builtin builtin_list[] = {
		{"cd", sh_cd},
		{"help", sh_help},
		{"exit",sh_exit},
		{"env", env},
		{NULL, NULL}
	};
	int i = 0;

	while (builtin_list[i].builtin_str != NULL && strcmp(s, builtin_list[i].builtin_str) != 0)
	{
		i++;
	}

	return (builtin_list[i].builtin_func);
}

int execute(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}
	if (get_function(args[0]) == NULL)
	{
		return (launch(args));
	}

	return (get_function(args[0])(args));
}

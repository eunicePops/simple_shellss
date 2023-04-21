#include "main.h"

char *builtin_str[] = {
	"cd",
	"help",
	"exit",
	"env"
};

int (*builtin_func[]) (char **) = {
	&sh_cd,
	&sh_help,
	&sh_exit,
	&env
};

int execute(char **args)
{
	int i;

	if (args[0] == NULL) {
		return 1;
	}
		for (i = 0; i < num_builtins(); i++) {
		    if (strcmp(args[0], builtin_str[i]) == 0) {
			return (*builtin_func[i])(args);
		}
	}
	return launch(args);
}

int num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}

int sh_help(__attribute__((unused))char **args)
{
	int i;
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < num_builtins(); i++) {
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return 1;
}

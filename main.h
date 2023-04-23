#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define TOK_DELIM " \t\r\n\a"
extern char **environ;

char *fget(char *s, int n, FILE *stream);
void parse_command(char *command, char **args);
int launch(char **args);
int execute(char **args);

/**
 * struct builtin - Struct builtin
 *
 * @builtin_str: The command entered
 * @builtin_func: The function called to handle the command
 */
typedef struct builtin
{
	char *builtin_str;
	int (*builtin_func)(char **);
} builtin;

int sh_cd(char **args);
int sh_help(__attribute__((unused))char **args);
int sh_exit(char **args);
int sh_env(char **args);

int (*get_function(char *s))(char **args);

#endif

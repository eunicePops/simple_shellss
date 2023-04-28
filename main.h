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

/**
 *struct infopass - this struct contains information to be passed into a function
 *@arg: a generated string
 *@argv: an array of strings generated from arg
 *@path: a path for the current command of string 
 *@argc: the count of the arguments 
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

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

/* token.c */
char **strtoks(char *, char *);
char **strtoks2(char *, char);


#endif

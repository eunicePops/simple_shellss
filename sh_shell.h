#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

char *fget(char *s, int n, FILE *stream);
char **sh_split_line(char *line);

int sh_launch(char **args);

#endif /* MAIN_H */

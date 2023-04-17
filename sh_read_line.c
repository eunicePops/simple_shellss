#include "sh_shell.h"

/**
 * fget - reads input
 * @s: array to store read characters
 * @n: number of arguments
 * @stream: where input comes from
 *
 * Return: read input or NULL if it fails
 */
char* fget(char* str, int n, FILE* stream)
{
	int c;
	char* ptr = str;

	while (--n > 0 && (c = getc(stream)) != EOF)
	{
		*ptr++ = c;
		if (c == '\n')
			break;
	}
	*ptr = '\0';
	if (ptr == str || c == EOF)
	{
		return NULL;
	}
	else
	{
		return str;
	}
}

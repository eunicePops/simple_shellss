#include "sh_shell.h"

/**
 * sh_read_line - read line and store it in allocated memory block,
 * and if it esceeeds it reallocate more space
 *
 * Return: buffer if successful
 */
char *sh_read_line()
{
	int bufsize = 1024;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (buffer == NULL)
	{
		perror("Error:");
	}
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\0')
		{
			cuffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
		if (position >= bufsize)
		{
			bufsize *= 2;
			buffer = realloc(buffer, bufsize);
			if (buffer != NULL)
			{
				exit(EXIT_FAILURE);
			}
		}
	}
}

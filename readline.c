#include "main.h"

char *fget(char *s, int n, FILE *stream)
{
	int c;
	char *ptr = s;

	while (--n > 0 && (c = getc(stream)) != EOF)
	{
		*ptr++ = c;
		if (c == '\n')
			break;
	}
	*ptr = '\0';
	if (ptr == s || c == EOF)
	{
		return (NULL);
	}
	else
	{
		return (s);
	}
}

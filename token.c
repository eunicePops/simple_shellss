#include "shell.h"

/**
 * **strtoks - this helps split a string into words. delimiters that are 
 * 		repeated are ignored
 * @istr: is the input string
 * @dl: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtoks(char *istr, char *dl)
{
	int l, j, k, m, numofwords = 0;
	char **u;

	if (istr == NULL || istr[0] == 0)
		return (NULL);
	if (!dl)
		dl = " ";
	for (l = 0; istr[l] != '\0'; l++)
		if (!is_delim(istr[l], dl) && (is_delim(istr[l + 1], dl) || !istr[l + 1]))
			numofwords++;

	if (numofwords == 0)
		return (NULL);
	u = malloc((1 + numofwords) * sizeof(char *));
	if (!u)
		return (NULL);
	for (l = 0, j = 0; j < numofwords; j++)
	{
		while (is_delim(istr[l], dl))
			l++;
		k = 0;
		while (!is_delim(istr[l + k], dl) && istr[l + k])
			k++;
		u[j] = malloc((k + 1) * sizeof(char));
		if (!u[j])
		{
			for (k = 0; k < j; k++)
				free(u[k]);
			free(u);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			u[j][m] = istr[l++];
		u[j][m] = 0;
	}
	u[j] = NULL;
	return (u);
}

/**
 * **strtoks2 - this function helps to splits a string into words
 * @istr: represents the input string
 * @dl: denotes the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtoks2(char *istr, char dl)
{
	int i, j, k, m, numofwords = 0;
	char **s;

	if (istr == NULL || istr[0] == 0)
		return (NULL);
	for (i = 0; istr[i] != '\0'; i++)
		if ((istr[i] != dl && istr[i + 1] == dl) ||
		    (istr[i] != dl && !istr[i + 1]) || istr[i + 1] == dl)
			numofwords++;
	if (numofwords == 0)
		return (NULL);
	s = malloc((1 + numofwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numofwords; j++)
	{
		while (istr[i] == dl && istr[i] != dl)
			i++;
		k = 0;
		while (istr[i + k] != dl && istr[i + k] && istr[i + k] != dl)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = istr[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

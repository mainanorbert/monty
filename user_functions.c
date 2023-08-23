#include "monty.h"
/**
 * _strdup - a function that duplicates string
 * @str: string to be duplicated
 * Return: returns duplicated string
 */
char *_strdup(char *str)
{
	char *duplicate = NULL;
	size_t length;

	if (str != NULL)
	{
		length = strlen(str);
		duplicate = malloc((length + 1) * sizeof(char));
		if (duplicate == NULL)
			return (NULL);
		strcpy(duplicate, str);
	}
	return (duplicate);
}

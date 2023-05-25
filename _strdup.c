#include "monty.h"

/**
 * _strdup - duplicates a string @str
 * @str: string to duplicate
 * Return: pointer to duplicated string or NULL if it fails
 */
char *_strdup(char *str)
{
	char *new_str;

	new_str = malloc(sizeof(char) * (strlen(str) + 1));
	if (new_str == NULL)
		return (NULL);
	strcpy(new_str, str);

	return (new_str);
}

#include "monty.h"

/**
 * _isalpha - check whether input is a letter of the alphabet
 *
 * @c: input character to test
 *
 * Return: 1 if true, 0 if false
 */

int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

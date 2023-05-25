#include "monty.h"

/**
 * _isdigit - checks if input is a digit (0 - 9) like the inbuilt isdigit
 * c function
 * @c: input to test
 * Return: 1 if digit, 0 if not
 */

int _isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

#include "monty.h"

/**
 * handle_pchar - prints the char at the top of the stack
 * @stack: pointer to stack
 * @line_number: line where the instruction exists on file
 * Return: void
 */
void handle_pchar(stack_t **stack, unsigned int line_number)
{
	int n;
	unsigned int l_no = line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_no);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if (!_isalpha(n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_no);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n);
}

#include "monty.h"

/**
 * handle_pstr - prints the string starting from the top of the stack
 * @stack: pointer to top of the stack
 * @line_number: line where opcode instruction is
 * Return: void
 */
void handle_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->n == 0 || !_isalpha(temp->n))
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	(void)line_number;
	putchar('\n');
}

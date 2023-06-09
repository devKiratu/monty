#include "monty.h"

/**
 * handle_pstr - prints the string starting from the top of the stack
 * @stack: pointer to top of the stack
 * @line_number: line where opcode instruction is
 * Return: void
 */
void handle_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	(void)line_number;
	printf("\n");
}

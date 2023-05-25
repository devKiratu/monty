#include "monty.h"

/**
 * handle_pall - processes opcode `pall` - prints all values on the stack
 * starting from the top
 * @stack: pointer to stack
 * @line_number: line where the instruction exists on file
 * Return: void
 */
void handle_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}

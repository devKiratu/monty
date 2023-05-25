#include "monty.h"

/**
 * handle_rotl - rotates the stack to the top
 *	the top element of the stack becomes the last one and the second top
 *	element of the stack becomes the first one
 * @stack: pointer to the top of the stack
 * @line_number: line where opcode instruction is issued
 * Return: void
 */
void handle_rotl(stack_t **stack, unsigned int line_number)
{
	int val;
	stack_t *temp;

	if (*stack == NULL)
		return;
	temp = *stack;
	val = temp->n;

	while (temp->next != NULL)
	{
		temp->n = (temp->next)->n;
		temp = temp->next;
	}
	temp->n = val;
	(void)line_number;
}

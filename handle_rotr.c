#include "monty.h"

/**
 * handle_rotr - rotates the stack to the bottom.
 *	- The last element of the stack becomes the top element
 * @stack: pointer to top element of the stack
 * @line_number: line where the rotr opcode is in the instruction set
 * Return: void
 */
void handle_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int new, current;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	new = temp->n;
	while (temp->next != NULL)
	{
		current = (temp->next)->n;
		(temp->next)->n = new;
		new = current;
		temp = temp->next;
	}
	(*stack)->n = current;
	(void)line_number;
}

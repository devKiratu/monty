#include "monty.h"

/**
 * handle_swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number where the instruction originated
 * Return: void
 */
void handle_swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	unsigned int l_no = line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_no);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = temp;
}

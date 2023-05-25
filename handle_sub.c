#include "monty.h"

/**
 * handle_sub - subtracts the top element from the second top
 * element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number where the instruction originated
 * Return: void
 */
void handle_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int diff = 0;
	unsigned int l_no = line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l_no);
		exit(EXIT_FAILURE);
	}
	diff = ((*stack)->next)->n - (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = diff;
	(*stack)->prev = NULL;
	free(temp);
}

#include "monty.h"

/**
 * handle_add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number where the instruction originated
 * Return: void
 */
void handle_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum = 0;
	unsigned int l_no = line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_no);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + ((*stack)->next)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;
	(*stack)->prev = NULL;
	free(temp);
}


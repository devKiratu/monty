#include "monty.h"

/**
 * handle_mod - computes the remainder of the division the second top element
 * of the stack by the top element
 * @stack: pointer to the top of the stack
 * @line_number: line number where the instruction originated
 * Return: void
 */
void handle_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int mod = 0;
	unsigned int l_no = line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_no);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_no);
		exit(EXIT_FAILURE);
	}
	mod = ((*stack)->next)->n % (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = mod;
	(*stack)->prev = NULL;
	free(temp);
}

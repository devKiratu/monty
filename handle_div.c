#include "monty.h"

/**
 * handle_div - divides the second top element of the stack by the top element
 * @stack: pointer to the top of the stack
 * @line_number: line number where the instruction originated
 * Return: void
 */
void handle_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result = 0;
	unsigned int l_no = line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l_no);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_no);
		exit(EXIT_FAILURE);
	}
	result = ((*stack)->next)->n / (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	(*stack)->prev = NULL;
	free(temp);
}

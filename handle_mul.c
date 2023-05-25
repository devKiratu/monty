#include "monty.h"

/**
 * handle_mul - multiplies the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number where the instruction originated
 * Return: void
 */
void handle_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int prod = 0;
	unsigned int l_no = line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_no);
		exit(EXIT_FAILURE);
	}
	prod = (*stack)->n * ((*stack)->next)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = prod;
	(*stack)->prev = NULL;
	free(temp);
}

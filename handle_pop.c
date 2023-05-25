#include "monty.h"

/**
 * handle_pop - removes top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number where the instruction originated
 * Return: void
 */
void handle_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

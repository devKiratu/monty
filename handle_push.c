#include "monty.h"

/**
 * handle_push - processes opcode `push` - pushes an element to the top of the
 * stack
 * @stack: pointer to stack
 * @line_number: line where the instruction exists on file
 * Return: void
 */
void handle_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (op_value == NULL || (atoi(op_value) == 0 && !_isdigit(*op_value)))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(op_value);
	new->next = NULL;
	new->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new;
		return;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

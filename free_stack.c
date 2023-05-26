#include "monty.h"

/**
 * free_stack - frees memory allocated to the stack
 * @stack: top of the stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

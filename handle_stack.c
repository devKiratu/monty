#include "monty.h"

/**
 * handle_stack - ensures all new elements are added to the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number where the instruction originated
 * Return: void
 */
void handle_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	stack_mode = 1;
}

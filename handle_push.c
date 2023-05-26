#include "monty.h"

unsigned int stack_mode = 1;

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
		fprintf(stderr, "Error: malloc failed\n");
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
	if (stack_mode)
		add_as_stack(stack, new);
	else
		add_as_queue(stack, new);
}

/**
 * add_as_stack - adds new element to top of stack (LIFO)
 * @stack: pointer to top of stack
 * @new: new stack element to add
 * Return: void
 */
void add_as_stack(stack_t **stack, stack_t *new)
{
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

/**
 * add_as_queue - adds new element to the end of queue (FIFO)
 * @stack: pointer to top of stack, which now acts as a queue
 * @new: new stack element to add
 * Return: void
 */
void add_as_queue(stack_t **stack, stack_t *new)
{
	stack_t *temp;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;
}

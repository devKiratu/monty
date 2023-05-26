#ifndef MONTY_H
#define MONTY_H

extern char *op_value;
extern unsigned int stack_mode;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_strdup(char *str);
int _isalpha(int c);
void process_opcodes(stack_t **stack, char *opcode, unsigned int line);
void handle_pall(stack_t **stack, unsigned int line_number);
void handle_push(stack_t **stack, unsigned int line_number);
void handle_pint(stack_t **stack, unsigned int line_number);
void handle_pop(stack_t **stack, unsigned int line_number);
void handle_swap(stack_t **stack, unsigned int line_number);
void handle_add(stack_t **stack, unsigned int line_number);
void handle_nop(stack_t **stack, unsigned int line_number);
void handle_sub(stack_t **stack, unsigned int line_number);
void handle_div(stack_t **stack, unsigned int line_number);
void handle_mul(stack_t **stack, unsigned int line_number);
void handle_mod(stack_t **stack, unsigned int line_number);
void handle_pchar(stack_t **stack, unsigned int line_number);
void handle_pstr(stack_t **stack, unsigned int line_number);
void handle_rotl(stack_t **stack, unsigned int line_number);
void handle_rotr(stack_t **stack, unsigned int line_number);
void handle_stack(stack_t **stack, unsigned int line_number);
void handle_queue(stack_t **stack, unsigned int line_number);
int _isdigit(int c);
void free_stack(stack_t *stack);
void add_as_stack(stack_t **stack, stack_t *new);
void add_as_queue(stack_t **stack, stack_t *new);

#endif

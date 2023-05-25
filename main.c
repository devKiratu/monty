#include "monty.h"

char *op_value;
/**
 * main - entry point to the program
 * @argc: commandline arguments count
 * @argv: commandline arguments array
 * Return: 0 on success, EXIT_FAILURE on any failure
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char buffer[1024], *s, *str, *token, *delim = " \n";
	unsigned int line = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((s = fgets(buffer, sizeof(buffer), fp)))
	{
		str = _strdup(s);
		token = strtok(str, delim);
		op_value = strtok(NULL, delim);

		if (token != NULL)
			process_opcodes(&stack, token, line);

		if (buffer[strlen(s) - 1] == '\n')
			line++;
		free(str);
	}
	fclose(fp);
	return (0);
}

/**
 * process_opcodes - checks input code and passes it to appropriate handler
 * @stack: pointer to stack
 * @opcode: potential opcode to be validated
 * @line: line containing instruction
 * Return: void
 */
void process_opcodes(stack_t **stack, char *opcode, unsigned int line)
{
	int len, found = 0, i = 0;

	instruction_t stack_ops[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pop", handle_pop},
		{"swap", handle_swap},
	};

	len = sizeof(stack_ops) / sizeof(instruction_t);
	while (i < len)
	{
		if (strcmp(opcode, stack_ops[i].opcode) == 0)
		{
			found = 1;
			stack_ops[i].f(stack, line);
			break;
		}
		i++;
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
}

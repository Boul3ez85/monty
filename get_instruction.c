#include "monty.h"

/**
 * 
 * 
 * 
 * 
 * 
 */

void get_instructions(char **tokens, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t op_codes[] =
	{
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (atoi(tokens[1]) != 0)
		stack_value = atoi(tokens[1]);
	if ((strcmp(tokens[0], "push") == 0) && isdigit(stack_value) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (op_codes[i].opcode != NULL)
	{
		if (strcmp(op_codes[i].opcode, tokens[0]) == 0)
			op_codes[i].f(stack, line_number);
		i++;
	}
}

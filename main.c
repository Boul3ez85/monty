#include "monty.h"

/**
 * 
 * 
 * 
 * 
 * 
 */
int stack_value;
int main(int argc, char **argv)
{
	FILE *fd;
	char *buffer;
	char **tokens;
	size_t size = 0;
	stack_t *stack = NULL;
	int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fd) != -1)
	{
		tokens = tokenizer(buffer);
		get_instructions(tokens, &stack, line_number);
		line_number++;
	}
	free_stack(stack);
	fclose(fd);
	return (0);
}

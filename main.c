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
	char **tokens, *token, *del = " \n";
	int i = 0;
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
	tokens = malloc(sizeof(char *) * 2);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fd) != -1)
	{
		i = 0;
		token = strtok(buffer, del);
		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			token = strtok(NULL, del);
		}
		get_instructions(tokens, &stack, line_number);
		line_number++;
	}
	fclose(fd);
	return (0);
}

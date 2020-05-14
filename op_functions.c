#include "monty.h"

/**
 * push - push an item into the stack
 * @stack: head of the stack
 * @line_number: line nmbr
 *
 * Return: Void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->next = *stack;
	new->prev = NULL;
	new->n = stack_value;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - function to print all
 * @stack: head of the stack
 * @line_number: line nmbr
 *
 * Return: Void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) <= 0 || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

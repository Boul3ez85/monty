#include "monty.h"

/**
 * mod - does nothing
 * @stack: head node
 * @line_number: line nmbr
 *
 * Return: Void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (stack_len(*stack) < 2 || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
}

/**
 * pchar - prints character of top stack
 * @stack: head node
 * @line_number: line nmbr
 *
 * Return: Void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	char c;

	temp = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	c = temp->n;
	if (isalpha(temp->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}

/**
 * pstr - prints string starting from top of the stack
 * @stack: head node
 * @line_number: line nmbr
 *
 * Return: Void
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	char c;

	(void)line_number;
	temp = *stack;
	while (stack_len(*stack) != 0)
	{
		if (isalpha(temp->n) == 0)
			break;
		c = temp->n;
		printf("%c", c);
		temp = temp->next;
	}
	printf("\n");
}

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
		free_stack(*stack);
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

/**
 * pint - print top stack
 * @stack: head node
 * @line_number: line nmbr
 *
 * Return: Void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 1 || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - delete head node
 * @stack: head node
 * @line_number: line nmbr
 *
 * Return: Void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 1 || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
}

/**
 * swap - swap the top two elements
 * @stack: head node
 * @line_number: line nmbr
 *
 * Return: Void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first_instack, *second_instack;
	int data;

	if (stack_len(*stack) < 2 || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	first_instack = *stack;
	second_instack = first_instack->next;
	data = first_instack->n;
	first_instack->n = second_instack->n;
	second_instack->n = data;
}

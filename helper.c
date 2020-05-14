#include "monty.h"

/**
 * free_stack - free a DLL
 * @stack: stack node
 *
 * Return: Void
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	stack = NULL;
}

/**
 * stack_len - counts lenght of doubly linked list
 * @stack: head node
 *
 * Return: lenght size_t
 */

size_t stack_len(const stack_t *stack)
{
	size_t len = 0;

	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

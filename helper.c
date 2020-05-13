#include "monty.h"

/**
 *free list - free a DLL
 *@stack: stack node
 *
 *Return: Void
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
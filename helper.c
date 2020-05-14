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

/**
 *delete_dnodeint_at_index - delete node at given index DLL
 *@stack: head node
 *@index: index
 *
 *Return: 1 on success, -1 on failure
 */

int delete_dnodeint_at_index(stack_t **stack, unsigned int index)
{
	stack_t *temp, *cur;
	unsigned int i = 0;

	temp = *stack;
	if (index == 0)
	{
		if (!temp)
			return (-1);
		*stack = temp->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
		return (1);
	}
	while (temp)
	{
		if (i == index - 1)
		{
			cur = temp->next;
			if (cur)
			{
				temp->next = cur->next;
				if (cur->next)
					cur->next->prev = temp;
				free(cur);
				return (1);
			}
		}
		temp = temp->next;
		i++;
	}
	return (-1);
}

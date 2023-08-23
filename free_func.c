#include "monty.h"
/**
 * free_arr - frees an array
 * @args: arrays to be freed
 */
void free_arr(char *args[])
{
	int i = 0;

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
}
/**
 * free_stack - a function that frees an array
 * @stack: the stack to be freed
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}

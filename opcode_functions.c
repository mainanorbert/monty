#include "monty.h"
/**
 * push_func - pushes an element to top of stack
 * @stack: pointer to pointer of the first element in a stack
 * line_number: the value to insert into stack
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_arr(x.args);
		free_stack(*stack);
		fclose(x.file);
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * pop_func - removes to element in stack
 * @stack: pointer to pointer of first element
 * Return: returns poped value
 */
/*void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int n;

	if (stack == NULL)
		printf("Stack is empty");
	n = (*stack)->n;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}*/
/**
 * pall_func - prints all elements of a stack
 * @stack: top elemennt in stack
 * @line_number: number of line read
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
	(void)line_number;
	/*free_stack(stack);*/
}
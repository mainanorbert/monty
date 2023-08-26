#include "monty.h"
/**
 * push_func - pushes an element to top of stack
 * @stack: pointer to pointer of the first element in a stack
 * @line_number: the value to insert into stack
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
 * @line_number: line currently executed
 */
void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_arr(x.args);
		fclose(x.file);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
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
/**
 * pint_func - function that prints top element of stack
 * @line_no: current line executed
 * @stack: stack to print its top element
 */
void pint_func(stack_t **stack, unsigned int line_no)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		free_arr(x.args);
		fclose(x.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * swap_func - function that swaps top two elements
 * @stack: pointer to pointer of stack swapped
 * @line_no: line number executed
 */
void swap_func(stack_t **stack, unsigned int line_no)
{
	stack_t *current;

	if (*stack == NULL || (*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		free_arr(x.args);
		free_stack(*stack);
		fclose(x.file);
		exit(EXIT_FAILURE);
	}
	current = (*stack)->next->next;
	(*stack)->next->next = current->next;
	(*stack)->next->prev = current;
	if (current->next != NULL)
		current->next->prev = (*stack)->next;
	current->next = (*stack)->next;
	current->prev = *stack;
	(*stack)->next = current;

}

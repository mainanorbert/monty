#include "monty.h"
/**
 * add_func - adds top two elements of stand
 * @stack: pointer to pointer of first element in stack
 * @line_no: line of code being executed
 */
void add_func(stack_t **stack, unsigned int line_no)
{
	int sum;
	stack_t *current = *stack;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		free_arr(x.args);
		free_stack(*stack);
		fclose(x.file);
		exit(EXIT_FAILURE);
	}
	sum = current->n + current->next->n;
	current->next->n = sum;
	pop_func(stack, line_no);
}
/**
 * nop_func - function that does nothing
 * @stack: pointer to ponter of first element in stack
 * @line_no: line being executed
 */
void nop_func(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
}
/**
 * sub_func - subtracts top element from second top
 * @stack: pointer to pointer of first element in stack
 * @line_no: line of opcode executed
 */
void sub_func(stack_t **stack, unsigned int line_no)
{
	int sub;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		free_arr(x.args);
		free_stack(*stack);
		fclose(x.file);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sub;
	pop_func(stack, line_no);
}

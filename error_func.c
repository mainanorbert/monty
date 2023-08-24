#include "monty.h"
/**
 * file_error - function that exits loop if file is inaccessible
 * @str: pointer to string with filename
 */
void file_error(char *str)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	exit(EXIT_FAILURE);
}
/**
 * invalid_error - handles invalid instruction
 * @line_no: the line error is encountered
 * @stack: stack of numbers
 */
void invalid_error(unsigned int line_no, stack_t *stack)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_no, x.args[0]);
	free_arr(x.args);
	free_stack(stack);
	fclose(x.file);
	exit(EXIT_FAILURE);
}

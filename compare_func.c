#include "monty.h"
/**
 * compare_func - compares and returns opcode to execute operation
 * @str: pointer to first element
 *
 * Return: returns a pointer to opcode function
 */
void (*compare_func(char *str))(stack_t **, unsigned int)
{
	unsigned int i = 0;

	instruction_t instructions[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"sub", sub_func},
		{"nop", nop_func},
		{NULL, NULL}};
	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, str) == 0)
		{
			return (instructions[i].f);
		}
		i++;
	}
	return (NULL);
}


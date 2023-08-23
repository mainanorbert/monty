#include "monty.h"
/**
 * check_push - checks second args of push is int
 * @s: string to check
 * @ar: array with bytcode
 * @l_no: line number
 * @stack: stack
 * Return: returns str if executable else NULL
 */
char *check_push(char *s, char *ar[], unsigned int l_no, stack_t *stack)
{
	int i = 0;

	if (s == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_no);
		free_arr(ar);
		free_stack(stack);
		fclose(x.file);
		exit(EXIT_FAILURE);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[0] == '-')
			continue;
		if (isdigit(s[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", l_no);
			free_arr(ar);
			free_stack(stack);
			fclose(x.file);
			exit(EXIT_FAILURE);
		}
	}
	return (s);
}

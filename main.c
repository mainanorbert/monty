#include "monty.h"
/**
 * main - entry point of program
 * @argc: number of arguments to main
 * @argv: array of strings
 */
op_t x;
int main(int argc, char *argv[])
{
	stack_t *top = NULL;
	unsigned int line_no = 1;
	char line[MAX_LINE_LENGTH], *tokens = NULL, *str = NULL;
	int token_count;
	void (*func)(stack_t **top, unsigned int line_number);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	x.file = fopen(argv[1], "r");
	if (x.file == NULL || access(argv[1], F_OK) != 0)
		file_error(argv[1]);
	while (fgets(line, sizeof(line), x.file) != NULL)
	{
		tokens = strtok(line, " \t\n"), token_count = 0;
		while (tokens != NULL && token_count < MAX_TOKENS_PER_LINE)
		{
			x.args[token_count] = _strdup(tokens), token_count++;
			tokens = strtok(NULL, " \t\n");
		}
		x.args[token_count] = NULL;
		if (x.args[0] == NULL)
		{
			line_no++;
			continue;
		}
		else
		{
			func = compare_func(x.args[0]);
			if (func == NULL)
				invalid_error(line_no, top);
			if (strcmp(x.args[0], "push") == 0)
				str = check_push(x.args[1], x.args, line_no, top), func(&top, atoi(str));
			else
				func(&top, line_no);
		}
		line_no++, free_arr(x.args);
	}
	fclose(x.file), free_stack(top);
	return (0);
}

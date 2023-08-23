#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_TOKENS_PER_LINE 10
#define MAX_LINE_LENGTH 100
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct op_s - args and file
 * @args: array of opcodes
 * @file: file to read from
 * Description: structure for file data and array
 */
typedef struct op_s
{
	char *args[MAX_TOKENS_PER_LINE];
	FILE *file;
} op_t;
extern op_t x;
void push_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);
void (*compare_func(char *str))(stack_t **, unsigned int);
char *check_push(char *s, char *ar[], unsigned int l_no, stack_t *stack);
void free_arr(char *args[]);
void free_stack(stack_t *stack);
char *_strdup(char *str);
#endif

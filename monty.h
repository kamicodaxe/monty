#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
	void (*f)(char *opcode, char *value_str, unsigned int line_number);
} instruction_t;

/* Global variables */
extern stack_t *stack;
extern instruction_t **instructions;

/** UTILS - ERROR */
int error_open_file(char *path);
int error_usage(void);

/** UTILS - FILE MANIPULATION */
int open_file(char *path);
ssize_t read_bytes(int fd, char **data);

/** UTILS - Stack */
char *_strtok_r(char *str, const char *delim, char **saveptr);
int is_numeric(const char *str);
stack_t *add_node(stack_t **stack, int n);
void free_stack(stack_t *stack);

void push(char *opcode, char *value_str, unsigned int line_number);
void pall(char *opcode, char *value_str, unsigned int line_number);
void pint(char *opcode, char *value_str, unsigned int line_number);
void pop(char *opcode, char *value_str, unsigned int line_number);
void swap(char *opcode, char *value_str, unsigned int line_number);
void add(char *opcode, char *value_str, unsigned int line_number);
void nop(char *opcode, char *value_str, unsigned int line_number);
void sub(char *opcode, char *value_str, unsigned int line_number);
void _div(char *opcode, char *value_str, unsigned int line_number);
void mul(char *opcode, char *value_str, unsigned int line_number);
void mod(char *opcode, char *value_str, unsigned int line_number);
void pchar(char *opcode, char *value_str, unsigned int line_number);
void pstr(char *opcode, char *value_str, unsigned int line_number);
void rotl(char *opcode, char *value_str, unsigned int line_number);

/** UTILS - MONTY */
void (*find_instruction(char *opcode))(char *, char *, unsigned int);
void parse_monty_file(char *data);

#endif /* MONTY_H */

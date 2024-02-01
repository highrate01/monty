#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list for stacks and queues
 *
 * @n: reps an integer
 * @prev: pointer to the previous of element on the stack 
 * @next: pointer to the next element on the stack or queue
 *
 * @Description: doubly linked list data structure
 * for stacks and queue
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

stack_t *global;
/**
 * struct instruction_s - opcode and and its function
 * @opcode: the opcode
 * @func: function for the opcode
 * Description: opcode and its function for stck and queues
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int argc, char *argv[]);
void push_element(stack_t **stack, unsigned int line_number);
void add_queue(stack_t **stack, int n);
void queue_func(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number);
void free_stack(stack_t *stack);
void pop_func(stack_t **stack, unsigned int line_number);
void add_func(stack_t **stack, unsigned int line_number);
int exec(char *content, stack_t **stack, unsigned int counter, FILE *file);
void pall_func(stack_t **stack, unsigned int line_number);
void div_func(stack_t **stack, unsigned int line_number);
void nop_func(stack_t **stack, unsigned int line_number);
void pchar_func(stack_t **stack, unsigned int line_number);
void pstr_func(stack_t **stack, unsigned int line_number);
void rotr_func(stack_t **stack, __attribute__((unused))unsigned int line_number);
void stack_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);
void add_node(stack_t **stack, int n);
void rotl_func(stack_t **stack, __attribute__((unused))unsigned int line_number);
void mod_func(stack_t **stack, unsigned int line_number);
void sub_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
void _comment(const char *line);
#endif /*MAIN_H*/

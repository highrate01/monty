#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE_SIZE 1024

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

/**
 * struct carrier_s - it is a struct type that contains
 * variables
 * @num: reps values
 * @nodes: pointer to nodes in the files
 * @content: line content
 * @lifi: flag change stack queue
 * Description: carries values trough the program
 */
typedef struct bus_s
{
	FILE *file;
	char *arg;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;

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
void push_element(stack_t **head, unsigned int counter);
void add_queue(stack_t **head, int n);
void queue_func(__attribute__((unused))stack_t **head, __attribute__((unused))unsigned int count);
void free_stack(stack_t *head);
void pop_func(stack_t **head, unsigned int counter);
void add_func(stack_t **head, unsigned int counter);
int exec(char *content, stack_t **stack, unsigned int counter, FILE *file);
void pall_func(stack_t **head, unsigned int counter);
void div_func(stack_t **head, unsigned int counter);
void nop_func(stack_t **head, unsigned int counter);
void pchar_func(stack_t **head, unsigned int counter);
void pstr_func(stack_t **head, unsigned int counter);
void rotr_func(stack_t **head, __attribute__((unused))unsigned int counter);
void stack_func(stack_t **head, unsigned int counter);
void pint_func(stack_t **head, unsigned int counter);
void swap_func(stack_t **head, unsigned int counter);
void add_node(stack_t **head, int n);
void rotl_func(stack_t **head, __attribute__((unused))unsigned int counter);
void modification(stack_t **head, unsigned int counter);
void sub_func(stack_t **head, unsigned int counter);
void mull_func(stack_t **head, unsigned int counter);

#endif /*MAIN_H*/

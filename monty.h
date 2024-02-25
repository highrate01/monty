#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stddef.h>
#define STACK 0
#define QUEUE 1
#define DELIMS "\n\t\a\b "

extern char **op_tok;

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
void f_push(stack_t **stack, unsigned int line_number);
int malloc_error(void);
int int_error(unsigned int line_number);
int usage_error(void);
int open_error(char *filename);
int op_error(char *op_code, int line_number);
int error_pchar(unsigned int line_number, char *op);
int error_div(unsigned int line_number);
int short_stack(unsigned int line_number, char *op);
int error_pint(unsigned int line_number);
int error_pop(unsigned int line_number);
void f_swap(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);
void f_pint(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void f_pstr(stack_t **stack, unsigned int line_number);
void f_pchar(stack_t **stack, unsigned int line_number);
void f_nop(stack_t **stack, unsigned int line_number);
void f_queue(stack_t **stack, unsigned int line_number);
void f_stack(stack_t **stack, unsigned int line_number);
void f_rotr(stack_t **stack, unsigned int line_number);
void f_rotl(stack_t **stack, unsigned int line_number);
void f_mod(stack_t **stack, unsigned int line_number);
void f_mul(stack_t **stack, unsigned int line_number);
void f_div(stack_t **stack, unsigned int line_number);
void f_sub(stack_t **stack, unsigned int line_number);
void f_add(stack_t **stack, unsigned int line_number);
void fill_number_buff(unsigned int num, unsigned int base, char *buff, int buff_size);
int get_len(unsigned int num, unsigned int base);
unsigned int _abs(int i);
char *get_int(int number);
char *get_next_word(char *str, char *delim);
int get_count(char *str, char *delim);
int get_count_length(char *str, char *delim);
int _isdelim(char cha, char *delim);
char **strtow(char *_str, char *delim);
int check_mode(stack_t *stack);
int inti_stack(stack_t **stack);
void free_stack(stack_t **stack);
void set_op_error(int err);
int file_func(FILE *fd);
int empty_line(char *line, char *delim);
void free_tok(void);
unsigned int token_len(void);
#endif

#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

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

extern int is_stack;

void read_file(char *m_file, stack_t **stack);
typedef void (*function_ptr)(stack_t **stack, unsigned int line_number);
function_ptr chk_function(char *opcode_m);
void push_m(stack_t **stack, unsigned int line_number);
void pint_m(stack_t **stack, unsigned int line_number);
void pall_m(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void pop_m(stack_t **stack, unsigned int line_number);
void swap_m(stack_t **stack, unsigned int line_number);
void add_m(stack_t **stack, unsigned int line_number);
void sub_m(stack_t **stack, unsigned int line_number);
void mul_m(stack_t **stack, unsigned int line_number);
void free_dlistint(stack_t *head);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void stack_m(__attribute__ ((unused)) stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number);
void queue_m(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused))unsigned int line_number);
void nop_m(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused))unsigned int line_number);
void mod_m(stack_t **stack, unsigned int line_number);
void div_m(stack_t **stack, unsigned int line_number);
void pstr_m(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void rotr_m(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void rotl_m(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
int isnumber(char *str);
void pchar_m(stack_t **stack, unsigned int line_number);


#endif /* MONTY_H */

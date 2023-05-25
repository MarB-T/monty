#include "monty.h"

/**
 * add_m - adds top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void add_m(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop_m(stack, line_number);
}

/**
 * sub_m - subtracts top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void sub_m(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop_m(stack, line_number);
}

/**
 * mul_m - multiply top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void mul_m(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop_m(stack, line_number);
}

/**
 * div_m - divides top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void div_m(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop_m(stack, line_number);
}

/**
 * mod_m - finds the mod of the stack top and the value bellow it
 * * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void mod_m(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop_m(stack, line_number);
}

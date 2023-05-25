#include "monty.h"

/**
 * push_m - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void push_m(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg;
	int oparand;

	oparand = 0;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	arg = strtok(NULL, "\n ");
	if (isnumber(arg) == 1 && arg != NULL)
	{
		oparand = atoi(arg);
	}
	else
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (is_stack == 1)
		add_dnodeint_end(stack, oparand);
	else if (is_stack == 0)
		add_dnodeint(stack, oparand);
}

/**
 * pall_m - prints all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pall_m(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * pint_m - print int at the top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void pint_m(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * swap_m - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void swap_m(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}

/**
 * pop_m - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pop_m(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
}

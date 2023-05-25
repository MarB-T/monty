#include "monty.h"

/**
 * pchar_m - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void pchar_m(stack_t **stack, unsigned int line_number)
{
	stack_t *stck;
	int val;

	if (*stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	stck = *stack;
	val = stck->n;

	if (!isprint(val))
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}

/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * rotl_m - rotates the list left
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void rotl_m(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *stck;
	int temp1, temp2;

	if (*stack == NULL)
		return;
	stck = *stack;
	while (stck->next)
		stck = stck->next;
	while (stck)
	{
		if (!stck->next)
		{
			temp1 = stck->n;
			stck->n = (*stack)->n;
		}
		else
		{
			temp2 = stck->n;
			stck->n = temp1;
			temp1 = temp2;
		}
		stck = stck->prev;
	}
}
/**
 * rotr_m - rotates the list right
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void rotr_m(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *run1, *run2;
	int temp1, temp2;

	if (*stack == NULL)
		return;

	run1 = *stack;
	run2 = *stack;
	while (run1->next)
		run1 = run1->next;
	while (run2)
	{
		if (run2->prev == NULL)
		{
			temp1 = run2->n;
			run2->n = run1->n;
		}
		else
		{
			temp2 = run2->n;
			run2->n = temp1;
			temp1 = temp2;
		}
		run2 = run2->next;

	}
}

/**
 * pstr_m - print string starting a top of stack
 * @stack: linked list for stack
 * @line_number: line number opcode occurs on
 */
void pstr_m(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *stck;
	int val;

	stck = *stack;

	while (stck != NULL)
	{
		val = stck->n;
		if (val == 0)
			break;
		if (!isprint(val))
		{
			break;
		}
		putchar(val);
		stck = stck->next;
	}
	putchar('\n');
}

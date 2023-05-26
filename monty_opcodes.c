#include "monty.h"

/**
 * read_file - reads the monty file and process each line
 * @monty_file: path to file containing the opcodes
 * @stack: pointer to stack
 */

void read_file(char *monty_file, stack_t **stack)
{
	FILE *m_file;
	int line_number = 1, close;
	char *opcode = NULL;
	function_ptr some_function;
	char *line_content; /* store content of line read */
	size_t i = 0; /* tracks size allocated to line_content  */
	ssize_t read; /*tracks number of chars read */

	m_file = fopen(monty_file, "r");
	if (m_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty_file);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line_content, &i, m_file)) != -1)
	{
		opcode = strtok(line_content, " \t");
		if (opcode[0] == '#')
		{
			line_number++;
			break;
		}
		some_function = chk_function(opcode);
		if (some_function == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		some_function(stack, line_number);
		line_number++;
	}
	if (line_content != NULL)
		free(line_content);
	close = fclose(m_file);
	if (close == -1)
	{
		fprintf(stderr, "File close error\n");
		exit(-1);
	}
}

/**
 * function_ptr - checks string in instruct and returns corresponding function
 * @opcode_m: the opcode to be checked in instruct
 * Return: function pointer of corresponding function
 */
function_ptr chk_function(char *opcode_m)
{
	int i = 0;

	instruction_t instruct[] = {
		{"push", push_m},
		{"pall", pall_m},
		{"pint", pint_m},
		{"pop", pop_m},
		{"swap", swap_m},
		{"pchar", pchar_m},
		{"add", add_m},
		{"sub", sub_m},
		{"div", div_m},
		{"mul", mul_m},
		{"mod", mod_m},
		{"nop", nop_m},
		{"rotr", rotl_m},
		{"rotl", rotl_m},
		{"stack", stack_m},
		{"queue", queue_m},
		{NULL, NULL}
	};
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, opcode_m) != 0)
	{
		i++;
	}
	return (instruct[i].f);
}

/**
 * stack_m - sets is_stack to stack
 * @stack: pointer to stack list
 * @line_number: line opcode occurs on
 */
void stack_m(__attribute__ ((unused)) stack_t **stack,
	    __attribute__ ((unused)) unsigned int line_number)
{
	is_stack = 0;
}
/**
 * queue_m - sets is_stack to queue
 * @stack: pointer to stack list
 * @line_number: line opcode occurs on
 */
void queue_m(__attribute__ ((unused))stack_t **stack,
	    __attribute__ ((unused))unsigned int line_number)
{
	is_stack = 1;
}

#include "monty.h"

int is_stack;
/** main - monty entry point
 * @argc: argument  count
 * @argv: argument vector
 *
 *
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char *monty_file;

	is_stack = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = argv[1];
	read_file(monty_file, &stack);
	free_dlistint(stack);
	return (0);

}

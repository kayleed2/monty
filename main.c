#include "monty.h"

/**
 * main - Interprets Monty ByteCodes files
 * @ac: Arg count
 * @argv: Argument passed in
 *
 * Return: 0 on success, exit status on failure
 */

int main(int ac, char *argv[])
{
	FILE *file;
	char op[30];
	int num, check;
	unsigned int i;
	void (*op_func)(stack_t **, unsigned int);
	stack_t **head = malloc(sizeof(stack_t));

	if (!head)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	if (ac != 2)
		fprintf(stderr, "USAGE: monty file\n"),	exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file  == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	for (i = 1; (check = fscanf(file, "%s", op)) != -1; i++)
	{
		if (strcmp(op, "nop") == 0)
			continue;
		else if (strcmp(op, "push") == 0)
		{
			check = fscanf(file, "%d", &num);
			if (check == 1)
				op_push(head, num);
			else
				fprintf(stderr, "L%d: usage: push integer\n", i), exit(EXIT_FAILURE);
		}
		else
		{
			op_func = get_op_func(op);
			if (op_func != NULL)
				op_func(head, i);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", i, op);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}

/**
 * op_push - Adds a new element to the stack
 * @head: the stack
 * @num: number to add
 * Return: Void
 */
void op_push(stack_t **head, int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->prev = NULL;
	new->next = *head;
	*head = new;
}

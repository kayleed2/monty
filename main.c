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
	char str[1000], **op;
	unsigned int i = 1;
	void (*op_func)(stack_t **, unsigned int);
	stack_t **head = malloc(sizeof(stack_t));

	if (!head)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	if (ac != 2)
		fprintf(stderr, "USAGE: monty file\n"),	exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);

	while (fgets(str, sizeof(str), file) != NULL)
	{
		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = '\0';
		op = splitter(str);
		if (op[0] == NULL)
			continue;
		else if (strcmp(op[0], "nop") == 0)
			continue;
		else if (strcmp(op[0], "push") == 0)
		{
 			if (op[1] != NULL)
				op_push(head, op[1], i);
			else
				fprintf(stderr, "L%d: usage: push integer\n", i), exit(EXIT_FAILURE);
		}
		else
		{
			op_func = get_op_func(op[0]);
			(op_func != NULL) ? (op_func(head, i)) :
			(fprintf(stderr, "L%d: unknown instruction %s\n", i, op[0]),
			exit(EXIT_FAILURE));
		}
		i++;
	}
	fclose(file);
	return (0);
}

/**
 * op_push - Adds a new element to the stack
 * @head: the stack
 * @num: number to add
 * Return: Void
 */
void op_push(stack_t **head, char *str, unsigned int i)
{
	stack_t *new;
	int num;

	num = atoi(str);
	if (num == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", i);
		exit(EXIT_FAILURE);
	}

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

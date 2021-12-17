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
		free(head), fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		free(head), fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	*head = NULL;
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
			{
				if (head != NULL)
					free_listint2(head);
				else
					printf("In else\n"), free(head);
				fclose(file), free(op), fprintf(stderr, "L%d: usage: push integer\n", i), exit(EXIT_FAILURE);
			}
		}
		else
		{
			op_func = get_op_func(op[0]), (op_func != NULL) ? (op_func(head, i)) :
				(fprintf(stderr, "L%d: unknown instruction %s\n", i, op[0]), fclose(file), free_listint2(head), free(op),
			exit(EXIT_FAILURE));
		}
		free(op), i++;
	}
	free_listint2(head), fclose(file);
	return (0);
}

/**
 * op_push - Adds a new element to the stack
 * @head: the stack
 * @str: String pushed
 * @i: Value given
 * Return: Void
 */
void op_push(stack_t **head, char *str, unsigned int i)
{
	stack_t *new;
	int num;

	if (strcmp(str, "0") == 0)
		num = 0;
	else
	{
		num = atoi(str);
		if (num == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", i);
			if (head != NULL)
				free_listint2(head);
			else
				free(head);
			exit(EXIT_FAILURE);
		}
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_listint2(head), exit(EXIT_FAILURE);
	}
	new->n = num;
	new->prev = NULL;
	if (head != NULL)
		new->next = *head;
	else
		new->next = NULL;
	*head = new;
}

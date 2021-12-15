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
	ssize_t read;
	char *op, *str = NULL;
	size_t len = 0;
	int num, check;
	unsigned int i;
	void (*op_func)(stack_t **, unsigned int);
	stack_t **new, **head = malloc(sizeof(stack_t));


	if (!head)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file  == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (i = 1; (check = fscanf(file, "%s", op)) != -1; i++)
	  {
		  if (strcmp(op, "push") == 0)
		  {
			  check = fscanf(file, "%d", &num);
			  if (check == 1)
			  {
				  new = malloc(sizeof(stack_t));
				  if (!new)
				  {
					  fprintf(stderr, "Error: malloc failed\n");
					  exit(EXIT_FAILURE);
				  }
				  (*new)->n = num;
				  (*new)->prev = NULL;
				  (*new)->next = *head;
				  *head = *new;
			  }
			  else
			  {
				  fprintf(stderr, "L%d: usage: push integer\n", i);
				  exit(EXIT_FAILURE);
			  }
		  }
		  else
		  {
			  printf("entering get_op\n");
			  op_func = get_op_func(op);
			  if (op_func != NULL)
			  {
				  op_func(head, i);
			  }
			  else if (op_func == NULL)
			  {
				  fprintf(stderr, "L%d: unknown instruction %s\n", i, op);
				  exit(EXIT_FAILURE);
			  }
		  }
	  }
	return (0);
}

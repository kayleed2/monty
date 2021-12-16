#include "monty.h"
/**
 * op_pall - Prints all values of stack
 * @head: Stack list
 * @i: Line number
 *
 * Return: Void
 */

void op_pall(stack_t **head, unsigned int i)
{
	stack_t *tmp;
	printf("this is pall\n");

	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * op_pint - Prints value at top of stack
 * @head: Stack list
 * @i: Line number
 * Return: Void
 */

void op_pint(stack_t **head, unsigned int i)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", i);
		exit(EXIT_FAILURE);
	}
	printf("made it to op_pint\n");
	printf("%d\n", (*head)->n);
}

/**
 * op_pop - Removes top element of stack
 * @head: Stack list
 * @i: Line number
 * Return: Void
 */

void op_pop(stack_t **head, unsigned int i)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", i);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	free(*head);
	*head = tmp;
	(*head)->prev = NULL;


}

/**
 * op_swap - Swaps top two elements of stack
 * @head: Stack list
 * @i: Line number
 * Return: Void
 */

void op_swap(stack_t **head, unsigned int i)
{
	stack_t *tmp;
	int swap;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", i);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	swap = (*head)->n;
	(*head)->n = tmp->n;
	tmp->n = swap;

}

/**
 * op_add - Adds top two elements of stack
 * @head: Stack list
 * @i: Line number
 * Return: Void
 */

void op_add(stack_t **head, unsigned int i)
{
	int a, b, sum;
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", i);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	a = (*head)->n;
	b = tmp->n;
	sum = a + b;

	*head = tmp;
	(*head)->n = sum;
	(*head)->prev = NULL;
	free(tmp->next);
	free(tmp->prev);
	free(tmp);



}

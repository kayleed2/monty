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
}

/**
 * op_pint - Prints value at top of stack
 * @head: Stack list
 * @i: Line number
 * Return: Void
 */

void op_pint(stack_t **head, unsigned int i)
{
}

/**
 * op_pop - Removes top element of stack
 * @head: Stack list
 * @i: Line number
 * Return: Void
 */

void op_pop(stack_t **head, unsigned int i)
{
}

/**
 * op_swap - Swaps top two elements of stack
 * @head: Stack list
 * @i: Line number
 * Return: Void
 */

void op_swap(stack_t **head, unsigned int i)
{
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
	stack_t **tmp;

	*tmp = (*head)->next;
	if (*tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", i);
		exit(EXIT_FAILURE);
	}

	a = (*head)->n;
	b = (*tmp)->n;
	sum = a + b;

	*head = *tmp;
	(*head)->prev = NULL;
	free((*tmp)->next);
	free((*tmp)->prev);
	free(*tmp);



}

#include "monty.h"

/**
 * free_listint2 - Frees listint_t
 * @head: Pointer to list
 * Return: Void
 **/

void free_listint2(stack_t **head)
{
	stack_t *tmp = *head;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	free(tmp);
	*head = NULL;
}

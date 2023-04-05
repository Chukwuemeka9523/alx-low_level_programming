#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL.
 * @head: Double pointer to the start of the list.
 *
 * Return: void.
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *next_node;

	if (!head)
		return;

	current = *head;

	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}

	*head = NULL;
}

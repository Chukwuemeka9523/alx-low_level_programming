#include "lists.h"

/**
 * free_listint - frees a list of type listint_t
 * @head: points to the head of the list
 *
 * Description: This function frees a linked list by iterating through each
 * node and freeing its memory.
 *
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	if (!head)
		return;
	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}


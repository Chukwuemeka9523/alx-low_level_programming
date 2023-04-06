#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node with a given value
 * at a specified
 * index position in a linked list.
 *
 * @head: A pointer to the pointer to the head node of the linked list.
 * @idx: The index position at which to insert the new node.
 * @n: The value to store in the new node.
 *
 * Return: A pointer to the new node on success, or NULL on failure.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	/** Declare variables */
	listint_t *before_insert;
	listint_t *new;
	unsigned int i;

	/** Check if head is NULL */
	if (!head)
		return (NULL);

	/** Initialize the location and create a new node */
	before_insert = *head;
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;

	/** Insert the new node at the beginning of the list */
	if (idx == 0)
	{
		new->next = before_insert;
		*head = new;
		return (*head);
	}

	/** Traverse the list to the insertion point */
	for (i = 0; i < (idx - 1); i++)
	{
		if (before_insert)
			before_insert = before_insert->next;
		else
			return (NULL);
	}

	/** Insert the new node at the specified index position */
	new->next = before_insert->next;
	before_insert->next = new;
	return (new);
}



#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a specified index
 * position in a linked list.
 *
 * @head: A pointer to the pointer to the head node of the
 * linked list.
 * @index: The index position of the node to delete.
 *
 * Return: 1 if the node is successfully deleted,
 * or -1 if the deletion fails.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *before_delete;
	listint_t *to_delete = NULL;

	/** Check if head or *head is NULL */
	if (!(head && *head))
		return (-1);

	/** Initialize the location of the node before the one to delete */
	before_delete = *head;

	/** Delete the node at the beginning of the list */
	if (index == 0)
	{
		to_delete = before_delete;
		*head = before_delete->next;
		free(to_delete);
		return (1);
	}

	/** Traverse the list to the deletion point */
	for (i = 0; i < (index - 1); i++)
	{
		if (before_delete->next)
			before_delete = before_delete->next;
		else
			return (-1);
	}

	/** Delete the node at the specified index position */
	to_delete = before_delete->next;
	before_delete->next = to_delete->next;
	free(to_delete);
	return (1);
}


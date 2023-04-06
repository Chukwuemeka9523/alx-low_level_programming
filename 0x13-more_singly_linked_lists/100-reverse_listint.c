#include "lists.h"

/**
 * reverse_listint - Reverses the order of a singly linked list.
 *
 * @head: A pointer to the pointer to the head node of the linked list.
 *
 * Return: A pointer to the new head node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL, *next = NULL;

	/** Reverse the order of the linked list */
	while (*head)
	{
		next = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = next;
	}

	/** Set the head pointer to the new head node of the reversed list */
	*head = previous;
	return (*head);
}


#include "lists.h"
/**
 * get_nodeint_at_index - returns the nth node of a linked list.
 * @head: a pointer to the head of the linked list.
 * @index: the index of the node to return.
 *
 * This function traverses the linked list starting from the head node
 * and returns the node at the specified index. The first node has an
 * index of 0.
 *
 * Return: If the node is found, return a pointer to it. Otherwise,
 * return NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);
	for (i = 0; i < index; i++)
	{
		if (head->next)
		head = head->next;
		else
			return (NULL);
	}
	return (head);
}

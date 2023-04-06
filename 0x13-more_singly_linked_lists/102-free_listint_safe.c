#include "lists.h"

/**
 * free_listint_safe - Frees a linked list, safely handling loops
 * @h: Pointer to a pointer to the head of the list
 *
 * Return: The number of nodes in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t numNodes = 0;
	listint_t *temp_node = NULL;

	if (!(h && *h))
		return (numNodes);

	while (*h)
	{
		numNodes++;

		if (*h > (*h)->next)
		{
			temp_node = *h;
			*h = (*h)->next;
			free(temp_node);
		}
		else
		{
			free(*h);
			*h = NULL;
		}
	}
	*h = NULL;
	return (numNodes);
}

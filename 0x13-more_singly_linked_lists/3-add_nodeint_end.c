#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of the list
 * @head: pointer to pointer to the start of the list
 * @n: integer value to add to the new node
 * Return: address of the new node or NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *current;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (current->next)
		current = current->next;

	current->next = new_node;
	return (new_node);
}

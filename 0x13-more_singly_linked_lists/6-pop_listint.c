#include "lists.h"

/**
 * pop_listint - deletes the head node of a list and returns its data (n)
 * @head: double pointer to the head of the list
 * Return: integer value of the deleted node's data
 */
int pop_listint(listint_t **head)
{
	listint_t *temp_node;
	int deleted_data = 0;

	if (!(*head))
		return (0);

	deleted_data += (*head)->n;

	temp_node = *head;
	*head = (*head)->next;

	free(temp_node);
	return (deleted_data);
}


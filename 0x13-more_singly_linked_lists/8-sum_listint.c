#include "lists.h"

/**
 * sum_listint - Returns the sum of all integer values in a linked list.
 * @head: A pointer to the head node of the list.
 *
 * Return: The sum of all integer values in the list,
 * or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}


#include "lists.h"

/**
 * print_listint_safe - prints list
 * @head: points to start of list
 * Return: number of nodes in size_t or exit 98 on failure
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count = 0;

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		node_count++;

		if (head > head->next)
		{
			head = head->next;
		}
		else
		{
			head = head->next;
			printf("-> [%p] %d\n", (void *)head, head->n);
			break;
		}
	}
	return (node_count);
}

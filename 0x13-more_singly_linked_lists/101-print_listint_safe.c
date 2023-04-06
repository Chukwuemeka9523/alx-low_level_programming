#include "lists.h"

/**
 * print_listint_safe - Prints a linked list of integers.
 *
 * @head: A pointer to the head node of the linked list.
 *
 * Return: The number of nodes in the linked list.
 *         If the function fails, exit with status code 98.
 */
#include "lists.h"

/**
 * print_listint_safe - prints list
 * @head: points to start of list
 * Return: number of nodes in size_t or exit 98 on failure
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t list_size = 0;

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		list_size++;

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
	return (list_size);
}

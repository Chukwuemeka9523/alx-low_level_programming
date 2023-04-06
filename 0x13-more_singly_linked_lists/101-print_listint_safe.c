#include "lists.h"

/**
 * print_listint_safe - Prints a linked list of integers.
 *
 * @head: A pointer to the head node of the linked list.
 *
 * Return: The number of nodes in the linked list.
 *         If the function fails, exit with status code 98.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;

	/** Traverse the linked list, printing each node's address and value */
	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;

		/** Check if the next node is already printed, indicating a loop */
		if (head > head->next)
		{
			head = head->next;
		}
		else /** Detected a loop, print the node and exit the loop */
		{
			head = head->next;
			printf("-> [%p] %d\n", (void *)head, head->n);
			break;
		}
	}

	return (count);
}


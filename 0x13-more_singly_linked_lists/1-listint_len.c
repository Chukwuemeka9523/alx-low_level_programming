#include "lists.h"

/**
 * listint_len - returns the number of elements in a listint_t list
 * @h: pointer to the head of the list
 * Return: the number of nodes in the list
*/
size_t listint_len(const listint_t *h)
{
size_t num_nodes = 0;

if (!h)
return (0);

while (h)
{
num_nodes += 1;
h = h->next;
}

return (num_nodes);
}

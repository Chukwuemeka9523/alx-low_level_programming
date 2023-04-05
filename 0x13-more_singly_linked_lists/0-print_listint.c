#include "lists.h"

/**
 * print_listint - prints all elements of listint_t
 * @h: points to the head of the list
 * Return: size_t (number of nodes)
*/
size_t print_listint(const listint_t *h)
{
size_t count = 0;

if (!h)
return (0);
while (h)
{
count += 1;
printf("%d\n", h->n);
h = h->next;
}
return (count);
}

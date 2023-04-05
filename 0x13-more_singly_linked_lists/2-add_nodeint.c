#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to pointer to the head of the list
 * @n: integer value to be stored in the new node
 * Return: pointer to the new node or NULL on failure
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;
listint_t *current_node;

if (!head)
return (NULL);
current_node = *head;
new_node = malloc(sizeof(listint_t));
if (!new_node)
return (NULL);
new_node->n = n;
new_node->next = current_node;
*head = new_node;

return (*head);
}

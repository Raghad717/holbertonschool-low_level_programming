#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer to list head
 * @idx: index where new node should be added
 * @n: value to add
 *
 * Return: address of the new node, or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *tmp;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	/* Insert at beginning */
	if (idx == 0)
		return (add_dnodeint(h, n));

	tmp = *h;

	/* Traverse to the position before idx */
	while (tmp != NULL && i < idx - 1)
	{
		tmp = tmp->next;
		i++;
	}

	/* If idx is out of range */
	if (tmp == NULL)
		return (NULL);

	/* Insert at end if tmp->next is NULL */
	if (tmp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* Insert in the middle */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = tmp;
	new_node->next = tmp->next;

	tmp->next->prev = new_node;
	tmp->next = new_node;

	return (new_node);
}

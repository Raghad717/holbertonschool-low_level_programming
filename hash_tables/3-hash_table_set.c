#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates an element in a hash table
 * @ht: The hash table
 * @key: The key (cannot be an empty string)
 * @value: The value associated with the key (will be duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node, *current;
	char *value_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	/* Check if key already exists → update value */
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			value_copy = strdup(value);
			if (value_copy == NULL)
				return (0);

			free(current->value);
			current->value = value_copy;
			return (1);
		}
		current = current->next;
	}

	/* Key not found → create new node */
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (0);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (0);
	}

	/* Insert at beginning of list (chaining) */
	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}

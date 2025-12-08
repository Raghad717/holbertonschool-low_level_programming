#include "hash_tables.h"

/**
 * update_value - Updates the value of an existing key
 * @node: The node to update
 * @value: The new value
 *
 * Return: 1 on success, 0 on failure
 */
int update_value(hash_node_t *node, const char *value)
{
	char *value_copy = strdup(value);

	if (value_copy == NULL)
		return (0);

	free(node->value);
	node->value = value_copy;
	return (1);
}

/**
 * create_node - Creates a new hash node
 * @key: The key
 * @value: The value
 *
 * Return: Pointer to the new node, or NULL on failure
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node = malloc(sizeof(hash_node_t));

	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - Adds or updates an element in a hash table
 * @ht: The hash table
 * @key: The key (must not be empty)
 * @value: The value to store (will be duplicated)
 *
 * Return: 1 on success*

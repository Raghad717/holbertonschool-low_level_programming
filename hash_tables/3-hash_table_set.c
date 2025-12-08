#include "hash_tables.h"

/**
 * update_value - replace node->value with a duplicate of value
 * @node: node to update
 * @value: new value
 *
 * Return: 1 on success, 0 on failure
 */
int update_value(hash_node_t *node, const char *value)
{
	char *dup = strdup(value);

	if (dup == NULL)
		return (0);
	free(node->value);
	node->value = dup;
	return (1);
}

/**
 * create_node - create a new hash node with duplicated key and value
 * @key: key string
 * @value: value string
 *
 * Return: pointer to new node or NULL on failure
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *n;

	n = malloc(sizeof(hash_node_t));
	if (n == NULL)
		return (NULL);

	n->key = strdup(key);
	if (n->key == NULL)
	{
		free(n);
		return (NULL);
	}

	n->value = strdup(value);
	if (n->value == NULL)
	{
		free(n->key);
		free(n);
		return (NULL);
	}

	n->next = NULL;
	return (n);
}

/**
 * hash_table_set - add or update an element in the hash table
 * @ht: hash table
 * @key: key (non-empty)
 * @value: value (duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *cur, *node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[idx];

	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
			return (update_value(cur, value));
		cur = cur->next;
	}

	node = create_node(key, value);
	if (node == NULL)
		return (0);

	node->next = ht->array[idx];
	ht->array[idx] = node;

	return (1);
}

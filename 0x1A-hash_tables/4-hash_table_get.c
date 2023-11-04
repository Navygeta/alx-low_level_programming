#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: Table to look into
 * @key: Unique identifier to look for
 * Return: Value or NULL if not found
 *
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int i = key_index((const unsigned char *)key, ht->size);
	hash_node_t **array = ht->array;
	hash_node_t *c_node;

	if (ht == NULL)
		return (NULL);

	for (c_node = array[i]; c_node != NULL; c_node = c_node->next)
	{
		if (strcmp(c_node->key, key) == 0)
		{
			return (c_node->value);
		}
	}

	return (NULL);
}

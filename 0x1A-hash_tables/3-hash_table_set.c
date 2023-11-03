#include "hash_tables.h"

/**
 * hash_table_set - Adds new element to the # table
 * @ht: Hash table to add or update new element to
 * @key: Unique string or unique identifying string
 * @value: Data associated with given key
 *
 * Return: 1 if it succeeded, 0 otherwise
 * In case of collision, adds the new node at the beginning of the list
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	new_node = malloc(sizeof(hash_node_t));

	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	if (value != NULL)
	{
		new_node->value = strdup(value);
		if (new_node->value == NULL)
		{
			free(new_node->key);
			free(new_node);
			return (0);
		}
	}
	else
	{
		new_node->value = NULL;
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

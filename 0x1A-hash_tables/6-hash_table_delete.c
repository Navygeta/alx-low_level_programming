#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *node, *temp;

	if (ht == NULL)
		return;

	while (i < ht->size)
	{
		node = ht->array[i];

		while (node != NULL)
		{
			temp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = temp;
		}

		i++;
	}

	free(ht->array);
	free(ht);
}

#include "hash_tables.h"

/**
 * hash_table_print - Function that prints a hash table
 * @ht: Table to be printed
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;

	if (ht == NULL)
	{
		printf("{}\n");
		return;
	}

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *c_node = ht->array[i];

		while (c_node != NULL)
		{
			printf("'%s': '%s'", c_node->key, c_node->value);
			if (c_node->next != NULL)
				printf(", ");
			c_node = c_node->next;
		}

		if (i < ht->size - 1 && ht->array[i + 1] != NULL)
			printf(", ");
	}

	printf("}\n");
}

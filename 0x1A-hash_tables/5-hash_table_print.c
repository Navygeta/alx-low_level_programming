#include "hash_tables.h"

/**
 * hash_table_print - Function that prints a hash table
 * @ht: Table to be printed
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int printed = 0;

	if (ht == NULL)
	{
		return;
	}

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *c_node = ht->array[i];

		while (c_node != NULL)
		{
			if (printed)
				printf(", ");

			printf("'%s': '%s'", c_node->key, c_node->value);

			printed = 1;

			c_node = c_node->next;
		}

	}

	printf("}\n");
}

#include "hast_tables.h"
/**
 * hash_table_create - Creates a hash table
 * @size: Array size
 * Return: Pointer to new hash table, or NULL if an error occurs
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_ht = NULL;
	unsigned long int i;

	if (size < 1)
	{
		return (NULL);
	}

	new_ht = malloc(sizeof(hash_table_t));
	if (new_ht == NULL)
	{
		return (NULL);
	}

	new_ht->array = malloc(sizeof(Node *) * size);
	if (new_ht->array == NULL)
	{
		free(new_ht);
		return (NULL);
	}

	for (i = 0; i < size; ++i)
	{
		new_ht->array[i] = NULL;
	}

	new_ht->size = size;

	return (new_ht);
}

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
	hash_node_t *nu_nod = NULL;
	unsigned long int index = 0;
	char *nu_key = strdup((char *)key);

	if (ht == NULL || key == NULL)
		return (0);

	nu_nod = malloc(sizeof(hash_node_t));
	if (nu_nod == NULL)
		return (0);

	nu_nod->key = nu_key;
	nu_nod->value = strdup((char *)value);
	index = key_index((const unsigned char *)nu_key, ht->size);

	if (ht->array[index] == NULL)
	{
		nu_nod->next = NULL;
		ht->array[index] = nu_nod;
	}
	else if (strcmp(ht->array[index]->key, nu_key) == 0)
	{
		free(ht->array[index]->value);
		ht->array[index]->value = nu_nod->value;
	}
	else
	{
		nu_nod->next = ht->array[index];
		ht->array[index] = nu_nod;
	}

	return (1);
}

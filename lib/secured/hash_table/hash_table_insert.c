/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** ashe_table_insert
*/

#include <stdlib.h>
#include "hashtable.h"

int ht_insert(hashtable_t *ht, char *key, void *value)
{
    data_t **data = NULL;
    data_t *tmp = NULL;
    int elem = 0;

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    data = ht->hash_data;
    elem = abs(ht->hash(key, ht->len)) % ht->len;
    tmp = data[elem];
    tmp = malloc(sizeof(data_t));
    tmp->cripted_code = ht->hash(key, ht->len);
    tmp->name = value;
    tmp->next = data[elem];
    data[elem] = tmp;
    return 0;
}

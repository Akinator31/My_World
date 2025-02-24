/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** ashe_table_insert
*/

#include <stdlib.h>
#include "my_lib.h"
#include "hashtable.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    data_t **data = NULL;
    data_t *tmp = NULL;
    int elem = 0;

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    ht_delete(ht, key);
    data = ht->hash_data;
    elem = abs(ht->hash(key, ht->len)) % ht->len;
    tmp = data[elem];
    tmp = malloc(sizeof(data_t));
    tmp->cripted_code = ht->hash(key, ht->len);
    tmp->name = malloc(sizeof(char) * (my_strlen(value) + 1));
    my_strcpy(tmp->name, value);
    tmp->next = data[elem];
    data[elem] = tmp;
    return 0;
}

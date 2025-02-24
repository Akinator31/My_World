/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** ashe_table_search
*/

#include <stdlib.h>
#include "hashtable.h"

void *ht_search(hashtable_t *ht, char *key)
{
    data_t **data = NULL;
    data_t *tmp = NULL;
    int code = 0;

    if (ht == NULL || key == NULL)
        return NULL;
    data = ht->hash_data;
    code = abs(ht->hash(key, ht->len));
    tmp = data[code % ht->len];
    while (tmp != NULL) {
        if (code == tmp->cripted_code) {
            return tmp->name;
        }
        tmp = tmp->next;
    }
    return NULL;
}

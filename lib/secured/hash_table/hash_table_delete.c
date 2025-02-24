/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** ashe_table_delete
*/

#include <stdlib.h>
#include "hashtable.h"

data_t *free_elem(data_t *data, int code, void (*destroy)(void *))
{
    data_t *tmp = data;
    data_t *list = data;

    if (code == data->cripted_code) {
        destroy(data->name);
        data = data->next;
        free(tmp);
        return data;
    }
    while (list != NULL && list->next != NULL) {
        if (code == list->next->cripted_code) {
            tmp = list->next;
            destroy(list->next->name);
            list->next = list->next->next;
            free(tmp);
        }
        list = list->next;
    }
    return data;
}

int ht_delete(hashtable_t *ht, char *key, void (*destroy)(void *))
{
    data_t **data = NULL;
    int i = 0;

    if (ht == NULL || key == NULL)
        return 84;
    i = abs(ht->hash(key, ht->len)) % ht->len;
    data = ht->hash_data;
    if (data[i] != NULL) {
        data[i] = free_elem(data[i], abs(ht->hash(key, ht->len)), destroy);
    }
    return 0;
}

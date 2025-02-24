/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** ashe_table_dump
*/

#include <stdlib.h>
#include "hashtable.h"

void ht_dump(hashtable_t *ht)
{
    data_t **data = NULL;
    data_t *tmp = NULL;

    if (ht == NULL)
        return;
    data = ht->hash_data;
    for (int i = 0; i < ht->len; i++) {
        tmp = data[i];
        mini_printf("[%d]:\n", i);
        while (tmp != NULL) {
            mini_printf("> %d - %s\n", tmp->cripted_code, tmp->name);
            tmp = tmp->next;
        }
    }
}

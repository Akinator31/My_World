/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** delete_ashe_table
*/

#include <stdlib.h>
#include "../include/hashtable.h"
#include "../include/struct.h"

void delete_hashtable(hashtable_t *ht)
{
    data_t **data = NULL;
    data_t *tmp = NULL;
    data_t *to_delete = NULL;

    if (ht == NULL)
        return;
    data = ht->hash_data;
    for (int i = 0; i < ht->len; i++) {
        tmp = data[i];
        while (tmp != NULL) {
            free(tmp->name);
            to_delete = tmp;
            tmp = tmp->next;
            free(to_delete);
        }
    }
    free(data);
    free(ht);
}

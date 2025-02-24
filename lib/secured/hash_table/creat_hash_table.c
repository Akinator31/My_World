/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** creat_ashe_table
*/

#include <stdlib.h>
#include "hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hashtable = NULL;
    data_t **data = NULL;

    if (len <= 0)
        return NULL;
    hashtable = malloc(sizeof(hashtable_t));
    data = malloc(sizeof(data_t *) * len);
    hashtable->len = len;
    hashtable->hash = hash;
    for (int i = 0; i < len; i++)
        data[i] = NULL;
    hashtable->hash_data = data;
    return hashtable;
}

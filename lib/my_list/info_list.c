/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** info_list
*/

#include <stdlib.h>
#include "my_list.h"

linked_list_t *new_list(void)
{
    return NULL;
}

void clear_list(linked_list_t *list)
{
    linked_list_t *temp = list;

    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
}

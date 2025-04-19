/*
** EPITECH PROJECT, 2025
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** add_data
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "my_list.h"
#include <stdarg.h>

linked_list_t *push_front_list(linked_list_t *list, void *data)
{
    linked_list_t *new_element = malloc(sizeof(linked_list_t));

    if (!new_element)
        return NULL;
    new_element->data = data;
    new_element->next = list;
    return new_element;
}

linked_list_t *push_front_list_all(linked_list_t *list, int nb, ...)
{
    va_list args;

    va_start(args, nb);
    for (int i = 0; i < nb; i++) {
        list = push_front_list(list, va_arg(args, void *));
        if (!list)
            return NULL;
    }
    va_end(args);
    return list;
}

linked_list_t *push_back_list(linked_list_t *list, void *data)
{
    linked_list_t *new_element = malloc(sizeof(linked_list_t));
    linked_list_t *temp = list;

    if (!new_element)
        return NULL;
    if (list == NULL) {
        new_element->data = data;
        new_element->next = NULL;
        return new_element;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    new_element->data = data;
    new_element->next = NULL;
    temp->next = new_element;
    return list;
}

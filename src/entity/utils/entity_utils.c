/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** entity_utils
*/

#include "entity.h"

int is_entity_from_node(linked_list_t *entity_node, int id)
{
    entity_t *entity = (entity_t *)(entity_node->data);

    return entity->id == id ? 1 : 0;
}

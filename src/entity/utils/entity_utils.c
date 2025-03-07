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

void entity_update_from_node(linked_list_t *entity_node,
    scene_t *scene, engine_t *engine)
{
    if (((entity_t *)(entity_node->data))->entity_update)
        ((entity_t *)(entity_node->data))->entity_update(
        ((entity_t *)(entity_node->data)), scene, engine);
}

void change_entity_state(scene_t *scene, int entity_id,
    int state_one, int state_two)
{
    linked_list_t *entity_list = scene->entity_list;
    entity_t *entity = NULL;

    while (entity_list) {
        entity = (entity_t *)(entity_list->data);
        if (entity->id == entity_id && entity->state == state_two) {
            entity->state = state_one;
            return;
        }
        if (entity->id == entity_id && entity->state == state_one) {
            entity->state = state_two;
            return;
        }
        entity_list = entity_list->next;
    }
}

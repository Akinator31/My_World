/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** get_scene_by_id
*/

#include "structure.h"
#include "engine.h"

scene_t *get_scene_by_id(engine_t *engine, int id)
{
    linked_list_t *temp = engine->scenes_list;

    while (temp != NULL) {
        if (((scene_t *)(temp->data))->id == id) {
            return ((scene_t *)(temp->data));
        }
        temp = temp->next;
    }
    return NULL;
}

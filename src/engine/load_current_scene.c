/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** load_current_scene
*/

#include "engine.h"
#include "structure.h"

void load_current_scene(engine_t *engine)
{
    linked_list_t *temp = engine->scenes_list;

    while (temp != NULL) {
        if (((scene_t *)(temp->data))->id == engine->current_scene->id)
            ((scene_t *)(temp->data))->scene_render(temp->data, engine);
        temp = temp->next;
    }
}

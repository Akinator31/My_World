/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** scenes_utils
*/

#include "structure.h"
#include "utils.h"

void change_scene(engine_t *engine, int id)
{
    engine->current_scene = get_scene_by_id(engine, id);
}

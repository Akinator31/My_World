/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** rotating
*/

#include "entity.h"
#include "structure.h"
#include "animations.h"

void rotate_unrotate_scale(float rotation,
    int *rotating_direction)
{
    if (rotation >= 5.0 && rotation <= 6.0)
        *rotating_direction = 1;
    if (rotation <= 355.0 && rotation >= 6.0)
        *rotating_direction = 0;
}

void rotating_button(entity_t *entity, UNUSED scene_t *scene,
    engine_t *engine)
{
    static int rotating_direction = 0;
    float rotation = sfSprite_getRotation(entity->sprite);
    sfSprite *sprite = entity->sprite;

    rotate_unrotate_scale(rotation, &rotating_direction);
    if (!rotating_direction)
        sfSprite_setRotation(sprite, rotation + (35 * engine->delta_time));
    else
        sfSprite_setRotation(sprite, rotation - (35 * engine->delta_time));
}

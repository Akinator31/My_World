/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** animations
*/

#include "entity.h"
#include "structure.h"
#include "animations.h"

void increase_decrease_scale(sfVector2f scale,
    sfVector2f origin_scale, int *scale_direction)
{
    if (scale.x > (origin_scale.x * 1.04) ||
        scale.y > (origin_scale.y * 1.04))
        *scale_direction = 0;
    if (scale.x < (origin_scale.x) || scale.y < (origin_scale.y))
        *scale_direction = 1;
}

void bouncing_button(entity_t *entity, UNUSED scene_t *scene,
    engine_t *engine)
{
    sfVector2f scale = sfSprite_getScale(entity->sprite);
    sfVector2f origin_scale = entity->original_scale;
    sfSprite *sprite = entity->sprite;

    increase_decrease_scale(scale, origin_scale, &entity->scale_direction);
    if (!entity->scale_direction)
        sfSprite_setScale(sprite,
            (sfVector2f){scale.x -(0.1 * engine->delta_time),
            scale.y - (0.1 * engine->delta_time)});
    else
        sfSprite_setScale(sprite,
            (sfVector2f){scale.x + (0.1 * engine->delta_time),
            scale.y + (0.1 * engine->delta_time)});
}

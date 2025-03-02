/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** scenes_utils
*/

#include "structure.h"
#include "utils.h"
#include "animations.h"

void change_animation(entity_t *entity,
    void (*f)(entity_t *entity, scene_t *scene, engine_t *engine),
    engine_t *engine)
{
    sfFloatRect texture_rect = sfSprite_getGlobalBounds(entity->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(engine->window);
    sfVector2u window_size = sfRenderWindow_getSize(engine->window);

    if (sfFloatRect_contains(&texture_rect, mouse_pos.x *
        (1920 / window_size.x), mouse_pos.y * (1080 / window_size.y))) {
        sfSprite_setScale(entity->sprite, entity->original_scale);
        entity->entity_update = f;
    } else {
        sfSprite_setRotation(entity->sprite, 0);
        entity->entity_update = bouncing_button;
    }
}

void change_scene(engine_t *engine, int id)
{
    engine->current_scene = get_scene_by_id(engine, id);
}

/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** rotating_hover
*/

#include "animations.h"

void button_anim(entity_t *entity, scene_t *scene,
    engine_t *engine)
{
    sfFloatRect texture_rect = sfSprite_getGlobalBounds(entity->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(engine->window);
    sfVector2u window_size = sfRenderWindow_getSize(engine->window);

    if (sfFloatRect_contains(&texture_rect, mouse_pos.x *
        (1920. / window_size.x), mouse_pos.y * (1080. / window_size.y))) {
            rotating_button(entity, scene, engine);
    } else {
        sfSprite_setRotation(entity->sprite, 0);
        bouncing_button(entity, scene, engine);
    }
}

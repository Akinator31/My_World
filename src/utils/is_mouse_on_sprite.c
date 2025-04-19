/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** is_mouse_on_sprite
*/

#include "structure.h"

sfBool is_mouse_on_sprite(engine_t *engine,
    sfSprite *sprite)
{
    sfFloatRect texture_rect = sfSprite_getGlobalBounds(sprite);
    sfVector2f window_size = {sfRenderWindow_getSize(engine->window).x,
        sfRenderWindow_getSize(engine->window).y};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(engine->window);

    if (sfFloatRect_contains(&texture_rect, mouse_pos.x *
        (1920 / window_size.x), mouse_pos.y * (1080 / window_size.y)))
        return sfTrue;
    return sfFalse;
}

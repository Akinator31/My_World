/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** check_screen_size
*/

#include "engine.h"

int check_screen_size(engine_t *engine, sfVector2u request_size)
{
    sfVector2u screen_size = sfRenderWindow_getSize(engine->window);

    return (request_size.x == screen_size.x) &&
        (request_size.y == screen_size.y);
}

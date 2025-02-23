/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** mute_or_unmute_music
*/

#include "structure.h"
#include "engine.h"

void mute_or_unmute_music(engine_t *engine, int mute_or_unmute)
{
    if (mute_or_unmute)
        sfMusic_pause(engine->ressources->menu_music);
    else
        sfMusic_play(engine->ressources->menu_music);
}

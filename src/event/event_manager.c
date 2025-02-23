/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** event_manager
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include "structure.h"
#include "utils.h"
#include "event.h"

void manage_music_button_hover(engine_t *engine, entity_t *entity)
{
    if (engine->music_state == PLAYING)
        set_sprite_hover(entity->sprite, engine,
            GET_RES(sound_on_button_hover), GET_RES(sound_on_button));
    else
        set_sprite_hover(entity->sprite, engine,
            GET_RES(sound_off_button_hover), GET_RES(sound_off_button));
}

void manage_pause_button_hover(engine_t *engine, entity_t *entity)
{
    if (engine->state == RUNNING)
        set_sprite_hover(entity->sprite, engine,
            GET_RES(pause_button_hover), GET_RES(pause_button));
    else
        set_sprite_hover(entity->sprite, engine,
            GET_RES(resume_button_hover), GET_RES(resume_button));
}

void manage_music(engine_t *engine, entity_t *entity)
{
    manage_music_button_hover(engine, entity);
    if (engine->event.type != sfEvtMouseButtonPressed)
        return;
    if (!is_mouse_on_sprite(engine, entity->sprite))
        return;
    if (sfTime_asSeconds(sfClock_getElapsedTime(engine->clock)) < 0.2)
        return;
    if (engine->music_state == PLAYING) {
        sfMusic_pause(engine->ressources->menu_music);
        sfClock_restart(engine->clock);
        engine->music_state = STOPPED;
    } else {
        sfMusic_play(engine->ressources->menu_music);
        sfClock_restart(engine->clock);
        engine->music_state = PLAYING;
    }
}

void analyse_event(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}

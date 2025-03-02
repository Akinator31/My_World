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
#include "events.h"
#include "scenes.h"
#include "animations.h"

void manage_music_button_hover(engine_t *engine, entity_t *entity)
{
    if (engine->music_state == PLAYING)
        set_sprite_hover(entity->sprite, engine,
            GET_RES("sound_on_hover"), GET_RES("sound_on"));
    else
        set_sprite_hover(entity->sprite, engine,
            GET_RES("sound_off_hover"), GET_RES("sound_off"));
}

void manage_music(engine_t *engine, entity_t *entity)
{
    manage_music_button_hover(engine, entity);
    change_animation(entity, rotating_button, engine);
    if (engine->event.type != sfEvtMouseButtonPressed)
        return;
    if (!is_mouse_on_sprite(engine, entity->sprite))
        return;
    if (sfTime_asSeconds(sfClock_getElapsedTime(entity->clock)) < 0.2)
        return;
    if (engine->music_state == PLAYING) {
        sfMusic_pause(GET_RES("menu_music"));
        sfClock_restart(entity->clock);
        engine->music_state = STOPPED;
    } else {
        sfMusic_play(GET_RES("menu_music"));
        sfClock_restart(entity->clock);
        engine->music_state = PLAYING;
    }
}

void analyse_event(engine_t *engine)
{
    if (engine->event.type == sfEvtClosed)
        engine->state = CLOSING;
    if (engine->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyQ))
        engine->state = CLOSING;
}

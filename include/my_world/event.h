/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** event
*/

#ifndef INCLUDED_EVENT_H
    #define INCLUDED_EVENT_H
    #include <SFML/Graphics.h>

void analyse_event(sfRenderWindow *window, sfEvent *event);
void manage_music(engine_t *engine, entity_t *entity);
void manage_pause_game(engine_t *engine, entity_t *entity);
void manage_chicken_click(entity_t *entity, engine_t *engine, scene_t *scene);

#endif

/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** event
*/

#ifndef INCLUDED_EVENT_H
    #define INCLUDED_EVENT_H
    #include <SFML/Graphics.h>
    #include "engine.h"

void analyse_event(engine_t *engine);
void manage_music(engine_t *engine, entity_t *entity);
void sleep_while_event(engine_t *engine, sfEventType event);
int is_event_on_entity(engine_t *engine,
    linked_list_t *entity_node, int entity_id);
void fetch_event(void *data);

#endif

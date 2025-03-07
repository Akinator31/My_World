/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** event_utils
*/

#include <SFML/Graphics.h>
#include "my_world.h"
#include "structure.h"
#include "utils.h"
#include "events.h"

void sleep_while_event(engine_t *engine, sfEventType event)
{
    while (engine->event.type == event)
        continue;
}

int is_event_on_entity(engine_t *engine,
    linked_list_t *entity_node, int entity_id)
{
    entity_t *entity = (entity_t *)(entity_node->data);

    if (engine->event.type == sfEvtMouseButtonPressed &&
        entity->id == entity_id && entity->state == ACTIVE &&
        is_mouse_on_sprite(engine, entity->sprite))
        return 1;
    return 0;
}

void fetch_event(void *data)
{
    engine_t *engine = NULL;
    bool has_to_close = false;

    if (data)
        engine = (engine_t *)data;
    while (!has_to_close) {
        while (sfRenderWindow_pollEvent(engine->window, &engine->event)
            && engine->state != CLOSING) {
            analyse_event(engine);
        }
        if (engine->state == CLOSING || engine->state == ERROR)
            has_to_close = true;
    }
    return;
}

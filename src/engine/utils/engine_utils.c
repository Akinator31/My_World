/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** engine_utils
*/

#include "engine.h"
#include "structure.h"
#include "events.h"

int tty_checker(char **envp)
{
    for (int i = 0; envp[i] != NULL; i++) {
        if ((envp[i][0] == 'D') && (envp[i][1] == 'I') && envp[i][2] == 'S')
            return 1;
    }
    return 0;
}

void set_icon(engine_t *engine)
{
    const sfUint8 *icon = NULL;

    if (!engine->ressources || !engine->ressources->hashtable)
        return;
    icon = sfImage_getPixelsPtr(GET_RES("icon"));
    if (engine->state != ERROR) {
        sfRenderWindow_setIcon(engine->window, 32, 32, icon);
    }
    return;
}

int check_state(engine_t *engine)
{
    if (engine->state == CLOSING || engine->state == ERROR)
        return 1;
    return 0;
}

void load_current_scene(engine_t *engine)
{
    linked_list_t *temp = engine->scenes_list;

    engine->delta_time = sfTime_asSeconds(sfClock_restart(engine->clock));
    while (temp != NULL) {
        if (((scene_t *)(temp->data))->id == engine->current_scene->id)
            ((scene_t *)(temp->data))->scene_render(temp->data, engine);
        temp = temp->next;
    }
}

static void launch_thread(engine_t *engine)
{
    sfThread_launch(engine->event_thread);
}

void init_thread(engine_t *engine)
{
    engine->event_thread = sfThread_create(fetch_event, engine);
    if (!engine->event_thread)
        engine->state = ERROR;
    launch_thread(engine);
}

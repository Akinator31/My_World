/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** engine
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "engine.h"
#include "my_lib.h"
#include "my_world.h"
#include "structure.h"
#include "ressources.h"
#include "hashtable.h"
#include "scenes.h"
#include "utils.h"

engine_t *load_game(unsigned int default_framerate, char **envp)
{
    engine_t *engine = calloc(1, sizeof(engine_t));

    if (!tty_checker(envp) || !engine) {
        if (engine)
            free(engine);
        return NULL;
    }
    engine->window = create_window(WIDTH, HEIGTH, NAME);
    engine->clock = sfClock_create();
    engine->ressources = create_ressources(engine);
    engine->scenes_list = load_scenes(engine);
    engine->default_fps_framerate = default_framerate;
    set_icon(engine);
    sfRenderWindow_setFramerateLimit(engine->window,
        default_framerate);
    return engine;
}

void clean_scene(linked_list_t *list)
{
    linked_list_t *temp = list;

    if (!list)
        return;
    while (list != NULL) {
        ((scene_t *)list->data)->scene_destroy(list->data);
        list = list->next;
    }
    clear_list(temp);
}

int engine_destroy(engine_t *engine, sfThread *event_thread)
{
    sfThread_destroy(event_thread);
    if (!engine)
        return 84;
    clean_scene(engine->scenes_list);
    sfRenderWindow_close(engine->window);
    sfRenderWindow_destroy(engine->window);
    sfClock_destroy(engine->clock);
    destroy_ressources(engine->ressources);
    if (engine->state == ERROR) {
        free(engine->ressources);
        free(engine);
        return 84;
    }
    free(engine->ressources);
    free(engine);
    return 0;
}

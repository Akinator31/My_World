/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "my_world.h"
#include "structure.h"
#include "engine.h"
#include "scenes.h"
#include "events.h"
#include "utils.h"

int main(int ac, char **av, char **envp)
{
    engine_t *engine = NULL;
    sfThread *event_thread = NULL;

    if (ac > 1)
        return help(ac, av);
    engine = load_game(60, envp);
    event_thread = sfThread_create(fetch_event, engine);
    sfThread_launch(event_thread);
    while ((engine != NULL) && !check_state(engine)) {
        sfRenderWindow_clear(engine->window, sfBlack);
        load_current_scene(engine);
        if (engine->state == RUNNING && ((scene_t *)(engine->current_scene))
            ->scene_update(engine->current_scene, engine) == 84) {
            sfThread_wait(event_thread);
            return engine_destroy(engine, event_thread);
        }
        sfRenderWindow_display(engine->window);
    }
    sfThread_wait(event_thread);
    return engine_destroy(engine, event_thread);
}

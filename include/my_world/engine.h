/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** engine
*/

#ifndef INCLUDED_ENGINE_H
    #define INCLUDED_ENGINE_H
    #include "my_lib.h"
    #include "my_world.h"
    #include "structure.h"
    #include "ressources.h"

// ENGINE INITIALIZATION
engine_t *load_game(unsigned int default_framerate, char **envp);
int engine_destroy(engine_t *engine, sfThread *event_thread);
void load_current_scene(engine_t *engine);

// ENGINE UTILS
int check_state(engine_t *engine);
int tty_checker(char **envp);
void set_icon(engine_t *engine);
void init_thread(engine_t *engine);

#endif

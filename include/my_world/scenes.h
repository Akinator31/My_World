/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** scenes
*/

#ifndef INCLUDED_SCENES_H
    #define INCLUDED_SCENES_H
    #include "my_list.h"
    #include "engine.h"

// SCENES INITIALIZATION
linked_list_t *load_scenes(engine_t *engine);
scene_t *init_main_page(engine_t *engine);
scene_t *init_settings_page(engine_t *engine);
scene_t *init_game_scene(engine_t *engine);
scene_t *init_creat_map_scene(engine_t *engine);

// SCENES UTILS
void change_scene(engine_t *engine, int id);

#endif

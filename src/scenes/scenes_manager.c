/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** scenes_manager
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "scenes.h"

linked_list_t *load_scenes(engine_t *engine)
{
    linked_list_t *scenes_list = new_list();
    scene_t *main_page = NULL;
    scene_t *settings_page = NULL;
    scene_t *game_scene = NULL;
    scene_t *creat_map_scene = NULL;

    if (engine->state == ERROR)
        return scenes_list;
    main_page = init_main_page(engine);
    settings_page = init_settings_page(engine);
    game_scene = init_game_scene(engine);
    creat_map_scene = init_creat_map_scene(engine);
    scenes_list = push_front_list(scenes_list, main_page);
    scenes_list = push_front_list(scenes_list, settings_page);
    scenes_list = push_front_list(scenes_list, game_scene);
    scenes_list = push_front_list(scenes_list, creat_map_scene);
    return scenes_list;
}

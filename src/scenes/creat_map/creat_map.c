/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** creat_map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SFML/Graphics/RenderStates.h>
#include "my_world.h"
#include "structure.h"
#include "entity.h"
#include "my_list.h"
#include "event.h"
#include "utils.h"
#include "engine.h"
#include "scenes.h"

void render_creat_map_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        if (((entity_t *)temp->data)->state == ACTIVE)
            sfRenderWindow_drawSprite(engine->window,
                ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

int update_button_hover_creat_map_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    switch_menu_music(engine);
    while (temp != NULL) {
        if (IS_ENTITY(1))
            set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("start_button_hover"), GET_RES("start_button"));
        if (IS_ENTITY(2))
            set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("start_button_hover"), GET_RES("start_button"));
        if (IS_ENTITY(3))
            set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("start_button_hover"), GET_RES("start_button"));
        if (IS_ENTITY(4))
            set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("start_button_hover"), GET_RES("start_button"));
        if (IS_ENTITY(5))
            set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("quit_button_hover"), GET_RES("quit_button"));
        temp = temp->next;
    }
    return 1;
}

int update_creat_map_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    update_button_hover_creat_map_scene(scene, engine);
    while (temp != NULL) {
        if (MOUSE_PRESSED() && IS_ENTITY(1) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite)) {
            engine->map3D = create_array_int(10);
            engine->map2D = create_2d_map(engine->map3D);
            engine->size_tab = 10;
            engine->current_scene = get_scene_by_id(engine, 3);
        }
        if (MOUSE_PRESSED() && IS_ENTITY(2) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite)) {
            engine->map3D = create_array_int(50);
            engine->map2D = create_2d_map(engine->map3D);
            engine->size_tab = 50;
            engine->current_scene = get_scene_by_id(engine, 3);
        }
        if (MOUSE_PRESSED() && IS_ENTITY(3) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite)) {
            engine->map3D = create_array_int(100);
            engine->map2D = create_2d_map(engine->map3D);
            engine->size_tab = 100;
            engine->current_scene = get_scene_by_id(engine, 3);
        }
        if (MOUSE_PRESSED() && IS_ENTITY(4) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite)) {
            engine->current_scene = get_scene_by_id(engine, 3);
        }
        if (MOUSE_PRESSED() && IS_ENTITY(5) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite))
            engine->current_scene = get_scene_by_id(engine, 1);   
        temp = temp->next;
    }
    return 0;
}

static void destroy_creat_map_scene(scene_t *scene)
{
    linked_list_t *temp = scene->entity_list;

    for (int i = 0; temp != NULL; i++) {
        ((entity_t *)temp->data)->entity_destroy(temp->data);
        temp = temp->next;
    }
    clear_list(scene->entity_list);
    sfClock_destroy(scene->clock);
    free(scene);
}

scene_t *init_creat_map_scene(engine_t *engine)
{
    linked_list_t *entity_list = new_list();
    scene_t *creat_map_scene = malloc(sizeof(scene_t));

    srand(time(NULL));
    sfMusic_setLoop(GET_RES("game_music"), sfTrue);
    entity_list = push_front_list_all(entity_list, 5,
        create_entity(GET_RES("start_button"), POS(960 - 150 - 500, 400), 1, NULL),
        create_entity(GET_RES("start_button"), POS(960 - 150, 400), 2, NULL),
        create_entity(GET_RES("start_button"), POS(960 - 150 + 500, 400), 3, NULL),
        create_entity(GET_RES("start_button"), POS(960 - 150, 700), 4, NULL),
        create_entity(GET_RES("start_button"), POS(1736, 30), 5, NULL));
    creat_map_scene->id = 4;
    creat_map_scene->clock = sfClock_create();
    creat_map_scene->entity_list = entity_list;
    creat_map_scene->scene_render = &render_creat_map_scene;
    creat_map_scene->scene_update = &update_creat_map_scene;
    creat_map_scene->scene_destroy = &destroy_creat_map_scene;
    return creat_map_scene;
}
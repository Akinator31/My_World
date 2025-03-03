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
#include "events.h"
#include "utils.h"
#include "engine.h"
#include "scenes.h"
#include "animations.h"

void render_creat_map_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(engine->window,
            ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

void update_button_hover_creat_map_scene(linked_list_t *temp,
    engine_t *engine)
{
    switch_menu_music(engine);
    if (is_entity_from_node(temp, 1))
        set_sprite_hover(GET_SPRITE(), engine,
        GET_RES("10x10_hover"), GET_RES("10x10"));
    if (is_entity_from_node(temp, 2))
        set_sprite_hover(GET_SPRITE(), engine,
        GET_RES("50x50_hover"), GET_RES("50x50"));
    if (is_entity_from_node(temp, 3))
        set_sprite_hover(GET_SPRITE(), engine,
        GET_RES("100x100_hover"), GET_RES("100x100"));
    if (is_entity_from_node(temp, 4))
        set_sprite_hover(GET_SPRITE(), engine,
        GET_RES("custom_hover"), GET_RES("custom"));
    if (is_entity_from_node(temp, 5))
        set_sprite_hover(GET_SPRITE(), engine,
        GET_RES("back_hover"), GET_RES("back"));
    if (is_entity_from_node(temp, 6))
        set_sprite_hover(GET_SPRITE(), engine,
        GET_RES("load_hover"), GET_RES("load"));
}

void set_map_size(int entity, int size, engine_t *engine, linked_list_t *temp)
{
    if (is_event_on_entity(engine, temp, entity)) {
        sleep_while_event(engine, sfEvtMouseButtonPressed);
        engine->map3D = create_array_int(size);
        engine->map2D = create_2d_map(engine->map3D);
        engine->size_tab = size;
        engine->current_scene = get_scene_by_id(engine, 3);
    }
}

int update_creat_map_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        update_button_hover_creat_map_scene(temp, engine);
        set_map_size(1, 10, engine, temp);
        set_map_size(2, 50, engine, temp);
        set_map_size(3, 100, engine, temp);
        entity_update_from_node(temp, scene, engine);
        if (is_event_on_entity(engine, temp, 4)) {
            sleep_while_event(engine, sfEvtMouseButtonPressed);
            change_scene(engine, 3);
        }
        if (is_event_on_entity(engine, temp, 5)) {
            sleep_while_event(engine, sfEvtMouseButtonPressed);
            change_scene(engine, 1);
        }
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

static linked_list_t *create_entity_list_map_scene(engine_t *engine)
{
    linked_list_t *entity_list = new_list();

    entity_list = push_front_list_all(entity_list, 7,
        create_entity(GET_RES("10x10"), POS(460, 475),
            1, button_anim),
        create_entity(GET_RES("50x50"), POS(960, 475), 2,
            button_anim),
        create_entity(GET_RES("100x100"), POS(1460, 475), 3,
            button_anim),
        create_entity(GET_RES("custom"), POS(960, 775), 4,
            button_anim),
        create_entity(GET_RES("back"), POS(1813, 105), 5,
            button_anim),
        create_entity(GET_RES("load"), POS(107, 105), 6,
            button_anim),
        create_entity(GET_RES("create_map_bg"), POS(960, 540), 7, NULL));
    return entity_list;
}

scene_t *init_creat_map_scene(engine_t *engine)
{
    scene_t *creat_map_scene = malloc(sizeof(scene_t));

    sfMusic_setLoop(GET_RES("game_music"), sfTrue);
    creat_map_scene->id = 4;
    creat_map_scene->clock = sfClock_create();
    creat_map_scene->entity_list = create_entity_list_map_scene(engine);
    creat_map_scene->scene_render = &render_creat_map_scene;
    creat_map_scene->scene_update = &update_creat_map_scene;
    creat_map_scene->scene_destroy = &destroy_creat_map_scene;
    return creat_map_scene;
}

/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** game_scene
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics/RenderStates.h>
#include "structure.h"
#include "entity.h"
#include "my_list.h"
#include "events.h"
#include "utils.h"
#include "scenes.h"
#include "animations.h"

void render_game_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        if (((entity_t *)temp->data)->state == ACTIVE) {
            draw_2d_map(engine);
            sfRenderWindow_drawSprite(engine->window,
                ((entity_t *)temp->data)->sprite, NULL);
        }
        temp = temp->next;
    }
}

void show_utils(scene_t *scene)
{
    change_entity_state(scene, 4, ACTIVE, OFF_SCREEN);
    change_entity_state(scene, 5, ACTIVE, OFF_SCREEN);
    change_entity_state(scene, 6, ACTIVE, OFF_SCREEN);
}

void update_button_game(linked_list_t *temp, engine_t *engine)
{
    entity_t *entity = (entity_t *)(temp->data);
    sfSprite *sprite = (sfSprite *)(entity->sprite);

    if (entity->id == 2)
        set_sprite_hover(sprite, engine,
        GET_RES("back_hover"), GET_RES("back"));
    if (entity->id == 3)
        set_sprite_hover(sprite, engine,
        GET_RES("pen_hover"), GET_RES("pen"));
    if (entity->id == 4)
        set_sprite_hover(sprite, engine,
        GET_RES("up_hover"), GET_RES("up"));
    if (entity->id == 6)
        set_sprite_hover(sprite, engine,
        GET_RES("down_hover"), GET_RES("down"));
    if (entity->id == 5)
        set_sprite_hover(sprite, engine,
        GET_RES("flat_hover"), GET_RES("flat"));
    temp = temp->next;
}

static void catch_event_on_map(engine_t *engine)
{
    if (engine->map == NULL) {
        change_scene(engine, 4);
    } else {
        key_pressed_on_map(engine);
        cmp_position(engine);
    }
}

static void manage_mouse_status(engine_t *engine, linked_list_t *entity_node)
{
    if (is_event_on_entity(engine, entity_node, 4)) {
        sleep_while_event(engine, sfEvtMouseButtonPressed);
        engine->mouse_status = 0;
    }
    if (is_event_on_entity(engine, entity_node, 5)) {
        sleep_while_event(engine, sfEvtMouseButtonPressed);
        engine->mouse_status = 2;
    }
    if (is_event_on_entity(engine, entity_node, 6)) {
        sleep_while_event(engine, sfEvtMouseButtonPressed);
        engine->mouse_status = 1;
    }
}

int update_game_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    catch_event_on_map(engine);
    switch_game_music(engine);
    while (temp != NULL) {
        manage_mouse_status(engine, temp);
        entity_update_from_node(temp, scene, engine);
        update_button_game(temp, engine);
        if (is_event_on_entity(engine, temp, 2)) {
            sleep_while_event(engine, sfEvtMouseButtonPressed);
            engine->map = free_map(engine->map);
            change_scene(engine, 4);
        }
        if (is_event_on_entity(engine, temp, 3)) {
            sleep_while_event(engine, sfEvtMouseButtonPressed);
            show_utils(scene);
        }
        temp = temp->next;
    }
    return 1;
}

static void destroy_game_scene(scene_t *scene)
{
    linked_list_t *temp = scene->entity_list;

    while (temp) {
        ((entity_t *)temp->data)->entity_destroy(temp->data);
        temp = temp->next;
    }
    clear_list(scene->entity_list);
    sfClock_destroy(scene->clock);
    free(scene);
}

static linked_list_t *create_entity_list_game_scene(engine_t *engine)
{
    linked_list_t *entity_list = new_list();
    entity_t *up_button = create_entity(GET_RES("up"),
        POS(107, 286), 4, button_anim);
    entity_t *flat_button = create_entity(GET_RES("flat"),
        POS(107, 467), 5, button_anim);
    entity_t *down_button = create_entity(GET_RES("down"),
        POS(107, 648), 6, button_anim);

    up_button->state = OFF_SCREEN;
    flat_button->state = OFF_SCREEN;
    down_button->state = OFF_SCREEN;
    entity_list = push_front_list_all(entity_list, 6,
        down_button,
        flat_button,
        up_button,
        create_entity(GET_RES("pen"), POS(107, 105), 3, button_anim),
        create_entity(GET_RES("back"), POS(1813, 105), 2, button_anim),
        create_entity(GET_RES("game_bg"), POS(960, 540), 1, NULL));
    return entity_list;
}

scene_t *init_game_scene(engine_t *engine)
{
    scene_t *game_scene = malloc(sizeof(scene_t));

    srand(time(NULL));
    sfMusic_setLoop(GET_RES("game_music"), sfTrue);
    game_scene->id = 3;
    game_scene->clock = sfClock_create();
    game_scene->entity_list = create_entity_list_game_scene(engine);
    game_scene->scene_render = &render_game_scene;
    game_scene->scene_update = &update_game_scene;
    game_scene->scene_destroy = &destroy_game_scene;
    return game_scene;
}

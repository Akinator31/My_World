/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** settings_page
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "scenes.h"
#include "structure.h"
#include "entity.h"
#include "my_list.h"
#include "events.h"
#include "utils.h"
#include "animations.h"

static void render_settings_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(engine->window,
            ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

void update_button_hover_settings(linked_list_t *temp, engine_t *engine)
{
    if (is_entity_from_node(temp, 3))
        set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("back_hover"), GET_RES("back"));
    if (is_entity_from_node(temp, 4))
        set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("900_hover"), GET_RES("900"));
    if (is_entity_from_node(temp, 5))
        set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("1920_hover"), GET_RES("1920"));
    if (is_entity_from_node(temp, 6))
        set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("4k_hover"), GET_RES("4k"));
}

void update_resolution_game(linked_list_t *temp, engine_t *engine)
{
    if (is_event_on_entity(engine, temp, 4) &&
        !check_screen_size(engine, SF_VECTOR_2U(900, 600))) {
        sfRenderWindow_setPosition(engine->window, SF_VECTOR_2I(0, 0));
        sfRenderWindow_setSize(engine->window, SF_VECTOR_2U(900, 600));
        engine->screen_size = SF_VECTOR_2I(900, 600);
    }
    if (is_event_on_entity(engine, temp, 5) &&
        !check_screen_size(engine, SF_VECTOR_2U(1920, 1080))) {
        sfRenderWindow_setPosition(engine->window, SF_VECTOR_2I(0, 0));
        sfRenderWindow_setSize(engine->window, SF_VECTOR_2U(1920, 1080));
        engine->screen_size = SF_VECTOR_2I(1920, 1080);
    }
    if (is_event_on_entity(engine, temp, 6) &&
        !check_screen_size(engine, SF_VECTOR_2U(3840, 2160))) {
        sfRenderWindow_setPosition(engine->window, SF_VECTOR_2I(0, 0));
        sfRenderWindow_setSize(engine->window, SF_VECTOR_2U(3840, 2160));
        engine->screen_size = SF_VECTOR_2I(3840, 2160);
    }
}

int update_settings_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        update_button_hover_settings(temp, engine);
        update_resolution_game(temp, engine);
        entity_update_from_node(temp, scene, engine);
        if (is_event_on_entity(engine, temp, 3)) {
            sleep_while_event(engine, sfEvtMouseButtonPressed);
            change_scene(engine, 1);
        }
        if (is_entity_from_node(temp, 2)) {
            manage_music(engine, temp->data);
        }
        temp = temp->next;
    }
    return 1;
}

void destroy_settings_page(scene_t *scene)
{
    linked_list_t *temp = scene->entity_list;

    while (temp) {
        ((entity_t *)temp->data)->entity_destroy(temp->data);
        temp = temp->next;
    }
    clear_list(scene->entity_list);
    free(scene);
}

static linked_list_t *create_entity_list_settings_scene(engine_t *engine)
{
    linked_list_t *entity_list = new_list();

    entity_list = push_front_list_all(entity_list, 6,
        create_entity(GET_RES("4k"), POS(435, 975), 6, button_anim),
        create_entity(GET_RES("1920"), POS(625, 775), 5, button_anim),
        create_entity(GET_RES("900"), POS(250, 775), 4, button_anim),
        create_entity(GET_RES("back"), POS(1813, 105), 3, button_anim),
        create_entity(GET_RES("sound_on"), POS(430, 577), 2, bouncing_button),
        create_entity(GET_RES("settings_bg"), POS(960, 540), 1, NULL));
    return entity_list;
}

scene_t *init_settings_page(engine_t *engine)
{
    linked_list_t *entity_list = new_list();
    scene_t *main_scene = malloc(sizeof(scene_t));

    entity_list = create_entity_list_settings_scene(engine);
    main_scene->id = 2;
    main_scene->entity_list = entity_list;
    main_scene->scene_render = &render_settings_page;
    main_scene->scene_update = &update_settings_page;
    main_scene->scene_destroy = &destroy_settings_page;
    return main_scene;
}

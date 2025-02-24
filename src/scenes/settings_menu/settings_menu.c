/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** settings_page
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_world.h"
#include "structure.h"
#include "entity.h"
#include "my_list.h"
#include "event.h"
#include "utils.h"

static void render_settings_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(engine->window,
            ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

int update_button_hover_settings(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        if (((entity_t *)(temp->data))->id == 3)
            set_sprite_hover(GET_SPRITE(), engine,
                GET_RES("back_hover"), GET_RES("back"));
        if (((entity_t *)(temp->data))->id == 4)
            set_sprite_hover(GET_SPRITE(), engine,
                GET_RES("900_hover"), GET_RES("900"));
        if (((entity_t *)(temp->data))->id == 5)
            set_sprite_hover(GET_SPRITE(), engine,
                GET_RES("1920_hover"), GET_RES("1920"));
        if (((entity_t *)(temp->data))->id == 6)
            set_sprite_hover(GET_SPRITE(), engine,
                GET_RES("4k_hover"), GET_RES("4k"));
        temp = temp->next;
    }
    return 1;
}

void update_resolution_game(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        if (MOUSE_PRESSED() && IS_ENTITY(4) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite)) {
            sfRenderWindow_setPosition(engine->window, SF_VECTOR_2I(0, 0));
            sfRenderWindow_setSize(engine->window, SF_VECTOR_2U(900, 600));
        }
        if (MOUSE_PRESSED() && IS_ENTITY(5) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite)) {
            sfRenderWindow_setPosition(engine->window, SF_VECTOR_2I(0, 0));
            sfRenderWindow_setSize(engine->window, SF_VECTOR_2U(1920, 1080));
        }
        if (MOUSE_PRESSED() && IS_ENTITY(6) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite)) {
            sfRenderWindow_setPosition(engine->window, SF_VECTOR_2I(0, 0));
            sfRenderWindow_setSize(engine->window, SF_VECTOR_2U(3840, 2160));
        }
        temp = temp->next;
    }
}

int update_settings_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    update_button_hover_settings(scene, engine);
    update_resolution_game(scene, engine);
    while (temp != NULL) {
        if (MOUSE_RELEASED() && IS_ENTITY(3) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite)) {
            engine->current_scene = get_scene_by_id(engine, 1);
        }
        if (((entity_t *)(temp->data))->id == 2) {
            manage_music(engine, temp->data);
        }
        temp = temp->next;
    }
    return 1;
}

void destroy_settings_page(scene_t *scene)
{
    linked_list_t *temp = scene->entity_list;

    for (int i = 0; temp != NULL; i++) {
        ((entity_t *)temp->data)->entity_destroy(temp->data);
        temp = temp->next;
    }
    clear_list(scene->entity_list);
    free(scene);
}

scene_t *init_settings_page(engine_t *engine)
{
    linked_list_t *entity_list = new_list();
    scene_t *main_scene = malloc(sizeof(scene_t));

    entity_list = push_front_list_all(entity_list, 6,
        create_entity(GET_RES("4k"), POS(285, 900), 6, NULL),
        create_entity(GET_RES("1920"), POS(475, 700), 5, NULL),
        create_entity(GET_RES("900"), POS(100, 700), 4, NULL),
        create_entity(GET_RES("back"), POS(1736, 30), 3, NULL),
        create_entity(GET_RES("sound_on"),
            POS(100, 500), 2, NULL),
        create_entity(GET_RES("settings_bg"),
            POS(0, 0), 1, NULL));
    main_scene->id = 2;
    main_scene->entity_list = entity_list;
    main_scene->scene_render = &render_settings_page;
    main_scene->scene_update = &update_settings_page;
    main_scene->scene_destroy = &destroy_settings_page;
    return main_scene;
}

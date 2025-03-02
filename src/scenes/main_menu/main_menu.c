/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** start_page
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_world.h"
#include "scenes.h"
#include "structure.h"
#include "entity.h"
#include "my_list.h"
#include "events.h"
#include "utils.h"
#include "engine.h"
#include "animations.h"

void render_main_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(engine->window,
            ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

void update_button_hover_main(linked_list_t *temp, engine_t *engine)
{
    entity_t *entity = (entity_t *)(temp->data);
    sfSprite *sprite = (sfSprite *)(entity->sprite);

    switch_menu_music(engine);
    if (entity->id == 2) {
        set_sprite_hover(sprite, engine,
        GET_RES("start_button_hover"), GET_RES("start_button"));
        change_animation(entity, rotating_button, engine);
    }
    if (entity->id == 3) {
        set_sprite_hover(sprite, engine,
        GET_RES("quit_button_hover"), GET_RES("quit_button"));
        change_animation(entity, rotating_button, engine);
    }
    if (entity->id == 4) {
        set_sprite_hover(sprite, engine,
        GET_RES("settings_button_hover"), GET_RES("settings_button"));
        change_animation(entity, rotating_button, engine);
    }
    temp = temp->next;
}

int update_main_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        update_button_hover_main(temp, engine);
        entity_update_from_node(temp, scene, engine);
        if (is_event_on_entity(engine, temp, 4)) {
            sleep_while_event(engine, sfEvtMouseButtonPressed);
            change_scene(engine, 2);
        }
        if (is_event_on_entity(engine, temp, 3)) {
            engine->state = CLOSING;
            return 84;
        }
        if (is_event_on_entity(engine, temp, 2))
            change_scene(engine, 4);
        temp = temp->next;
    }
    return 0;
}

void destroy_main_page(scene_t *scene)
{
    linked_list_t *temp = scene->entity_list;

    for (int i = 0; temp != NULL; i++) {
        ((entity_t *)temp->data)->entity_destroy(temp->data);
        temp = temp->next;
    }
    clear_list(scene->entity_list);
    free(scene);
}

scene_t *init_main_page(engine_t *engine)
{
    linked_list_t *entity_list = new_list();
    scene_t *main_scene = calloc(1, sizeof(scene_t));

    sfMusic_setLoop(GET_RES("menu_music"), sfTrue);
    sfMusic_play(GET_RES("menu_music"));
    entity_list = push_front_list_all(entity_list, 4,
        create_entity(GET_RES("start_button"), POS(300, 875), 2,
            bouncing_button),
        create_entity(GET_RES("quit_button"), POS(1813, 105), 3,
            bouncing_button),
        create_entity(GET_RES("settings_button"), POS(579, 877), 4,
            bouncing_button),
        create_entity(GET_RES("background"), POS(960, 540), 1, NULL));
    main_scene->id = 1;
    main_scene->entity_list = entity_list;
    main_scene->scene_render = &render_main_page;
    main_scene->scene_update = &update_main_page;
    main_scene->scene_destroy = &destroy_main_page;
    engine->current_scene = main_scene;
    return main_scene;
}

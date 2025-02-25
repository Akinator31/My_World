/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** start_page
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_world.h"
#include "structure.h"
#include "entity.h"
#include "my_list.h"
#include "event.h"
#include "utils.h"
#include "engine.h"

void render_main_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(engine->window,
            ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

int update_button_hover_main(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    switch_menu_music(engine);
    while (temp != NULL) {
        if (IS_ENTITY(2))
            set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("start_button_hover"), GET_RES("start_button"));
        if (IS_ENTITY(3))
            set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("quit_button_hover"), GET_RES("quit_button"));
        if (IS_ENTITY(4))
            set_sprite_hover(GET_SPRITE(), engine,
            GET_RES("settings_button_hover"), GET_RES("settings_button"));
        temp = temp->next;
    }
    return 1;
}

int update_main_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    update_button_hover_main(scene, engine);
    while (temp != NULL) {
        if (MOUSE_PRESSED() && IS_ENTITY(4) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite))
                engine->current_scene = get_scene_by_id(engine, 2);
        if (MOUSE_PRESSED() && IS_ENTITY(3) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite)) {
            sfRenderWindow_close(engine->window);
            return 84;
        }
        if (MOUSE_PRESSED() && IS_ENTITY(2) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite))
                engine->current_scene = get_scene_by_id(engine, 4);
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
    scene_t *main_scene = malloc(sizeof(scene_t));

    sfMusic_setLoop(GET_RES("menu_music"), sfTrue);
    sfMusic_play(GET_RES("menu_music"));
    entity_list = push_front_list_all(entity_list, 4,
        create_entity(GET_RES("start_button"), POS(150, 800), 2, NULL),
        create_entity(GET_RES("quit_button"), POS(1736, 30), 3, NULL),
        create_entity(GET_RES("settings_button"), POS(500, 800), 4, NULL),
        create_entity(GET_RES("background"), POS(0, 0), 1, NULL));
    main_scene->id = 1;
    main_scene->entity_list = entity_list;
    main_scene->scene_render = &render_main_page;
    main_scene->scene_update = &update_main_page;
    main_scene->scene_destroy = &destroy_main_page;
    engine->state = RUNNING;
    engine->current_scene = main_scene;
    return main_scene;
}

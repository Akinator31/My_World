/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** game_scene
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

void render_game_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        if (((entity_t *)temp->data)->state == ACTIVE)
            sfRenderWindow_drawSprite(engine->window,
                ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

int update_game_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    draw_2d_map(engine);
    switch_game_music(engine);
    while (temp != NULL) {
        entity_update_from_node(temp, scene, engine);
        if (((entity_t *)(temp->data))->id == 2) {
            set_sprite_hover(((entity_t *)(temp->data))->sprite, engine,
            GET_RES("back_hover"),
            GET_RES("back"));
        }
        if (is_event_on_entity(engine, temp, 2)) {
            sleep_while_event(engine, sfEvtMouseButtonPressed);
            change_scene(engine, 4);
        }
        temp = temp->next;
    }
    return 1;
}

static void destroy_game_scene(scene_t *scene)
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

static linked_list_t *create_entity_list_game_scene(engine_t *engine)
{
    linked_list_t *entity_list = new_list();

    entity_list = push_front_list_all(entity_list, 2,
        create_entity(GET_RES("back"), POS(1813, 105), 2, button_anim),
        create_entity(GET_RES("game_bg"), POS(960, 540), 1, NULL));
    return entity_list;
}

scene_t *init_game_scene(engine_t *engine)
{
    linked_list_t *entity_list = new_list();
    scene_t *game_scene = malloc(sizeof(scene_t));

    srand(time(NULL));
    sfMusic_setLoop(GET_RES("game_music"), sfTrue);
    entity_list = push_front_list_all(entity_list, 2,
        create_entity(GET_RES("back"), POS(1813, 105), 2, button_anim),
        create_entity(GET_RES("game_bg"), POS(960, 540), 1, NULL));
    game_scene->id = 3;
    game_scene->clock = sfClock_create();
    game_scene->entity_list = create_entity_list_game_scene(engine);
    game_scene->scene_render = &render_game_scene;
    game_scene->scene_update = &update_game_scene;
    game_scene->scene_destroy = &destroy_game_scene;
    return game_scene;
}

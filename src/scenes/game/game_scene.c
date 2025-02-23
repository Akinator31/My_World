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
#include "event.h"
#include "utils.h"
#include "engine.h"
#include "scenes.h"

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

    switch_game_music(engine);
    while (temp != NULL) {
        if (((entity_t *)(temp->data))->id == 2) {
            set_sprite_hover(((entity_t *)(temp->data))->sprite, engine,
            engine->ressources->quit_button_hover,
            engine->ressources->quit_button);
        }
        if (MOUSE_PRESSED() && IS_ENTITY(2) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite))
                engine->current_scene = get_scene_by_id(engine, 1);
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

scene_t *init_game_scene(engine_t *engine)
{
    linked_list_t *entity_list = new_list();
    scene_t *game_scene = malloc(sizeof(scene_t));

    srand(time(NULL));
    sfMusic_setLoop(GET_RES(game_music), sfTrue);
    entity_list = push_front_list_all(entity_list, 2,
        create_entity(GET_RES(quit_button), POS(30, 30), 2, NULL),
        create_entity(GET_RES(game_background), POS(0, 0), 1, NULL));
    game_scene->id = 3;
    game_scene->clock = sfClock_create();
    game_scene->entity_list = entity_list;
    game_scene->scene_render = &render_game_scene;
    game_scene->scene_update = &update_game_scene;
    game_scene->scene_destroy = &destroy_game_scene;
    return game_scene;
}

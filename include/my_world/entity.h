/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** entity
*/

#ifndef INCLUDED_ENTITY_H
    #define INCLUDED_ENTITY_H
    #include "structure.h"

// ENTITY INITIALIZATION
entity_t *create_entity(sfTexture *texture, sfVector2f pos, int id,
    void (*entity_update)(entity_t *entity, scene_t *scene, engine_t *engine));
entity_t *create_text(int text, sfVector2f pos, engine_t *engine);
void destroy_entity(entity_t *entity);
void destroy_text_entity(entity_t *entity);

// ENTITY UTILS
int is_entity_from_node(linked_list_t *entity_node, int id);
void entity_update_from_node(linked_list_t *entity_node,
    scene_t *scene, engine_t *engine);
void change_entity_state(scene_t *scene, int entity_id,
    int state_one, int state_two);

#endif

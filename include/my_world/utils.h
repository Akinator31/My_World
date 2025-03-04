/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H
    #include <SFML/Graphics.h>
    #include "engine.h"
    #define ANGLE_X 45
    #define ANGLE_Y 35
    #define TAB_SIZE 100
    #define OFFSET_X 960
    #define OFFSET_Y 50
    #define HITBOX_RANGE 15

sfRenderWindow *create_window(unsigned int width,
    unsigned int heigth, char *window_title);
void set_sprite_hover(sfSprite *sprite, engine_t *engine,
    sfTexture *new_texture, sfTexture *original_texture);
sfBool is_mouse_on_sprite(engine_t *engine,
    sfSprite *sprite);
scene_t *get_scene_by_id(engine_t *engine, int id);
void mute_or_unmute_music(engine_t *engine, int mute_or_unmute);
void switch_game_music(engine_t *engine);
void switch_menu_music(engine_t *engine);
void switch_pause_music(engine_t *engine);
int help(int ac, char **av);
sfVector2f get_random_pos(engine_t *engine);
int check_screen_size(engine_t *engine, sfVector2u request_size);
int **create_array_int(int size);
sfVector2f **create_2d_map(map_t *map);
int draw_2d_map(engine_t *engine);
void multi_array_vector(sfVector2f **array, float multi);
void get_input_on_map(engine_t *engine);
sfVector2f project_iso_point(int x, int y, map_t *map);
map_t *free_map(map_t *map);
sfVector2f **change_2d_map(map_t *map);
void move_map_input(engine_t *engine);
void cmp_position(engine_t *engine);
void key_pressed_on_map(engine_t *engine);
int alloc_error(engine_t *engine, void *data);

#endif
